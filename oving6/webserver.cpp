#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class WebServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_context &io_context) : socket(io_context) {}
  };

  boost::asio::io_context io_context;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  string get_http_path(string message) {
    istringstream iss(message);

    string httpMethod;
    string httpPath;
    string httpVersion;

    iss >> httpMethod >> httpPath >> httpVersion;

    return httpPath;
  }

  string make_http_response(int status_code, const string &status_message, const string &body) {
    string status_line = "HTTP/1.1 " + to_string(status_code) + " " + status_message + "\r\n";
    string headers = "Content-Type: text/plain\r\n"
                     "Content-Length: " + to_string(body.size()) + "\r\n\r\n";

    return status_line + headers + body;
  }

  string route(string path) {
    if (path == "/") {
      return make_http_response(200, "OK", "Dette er hjemmesiden");
    } else if (path == "/en_side") {
      return make_http_response(200, "OK", "Dette er en side");
    } else {
      return make_http_response(404, "Not Found", "404 Not Found");
    }
  }

  void handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    // Read from client until newline ("\r\n")
    async_read_until(connection->socket, *read_buffer, "\r\n", [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
      // If not error:
      if (!ec) {
        // Retrieve message from client as string:
        istream read_stream(read_buffer.get());
        std::string message;
        getline(read_stream, message);
        message.pop_back(); // Remove "\r" at the end of message

        string path = get_http_path(message);

        string http_response = route(path);

        // Close connection when "exit" is retrieved from client
        if (message == "exit")
          return;

        auto write_buffer = make_shared<boost::asio::streambuf>();
        ostream write_stream(write_buffer.get());

        // Add message to be written to client:
        write_stream << http_response << "\r\n";

        // Write to client
        async_write(connection->socket, *write_buffer, [this, connection, write_buffer](const boost::system::error_code &ec, size_t) {
          // If not error:
          if (!ec)
            handle_request(connection);
        });
      }
    });
  }

  void accept() {
    // The (client) connection is added to the lambda parameter and handle_request
    // in order to keep the object alive for as long as it is needed.
    auto connection = make_shared<Connection>(io_context);

    // Accepts a new (client) connection. On connection, immediately start accepting a new connection
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      // If not error:
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  WebServer() : endpoint(tcp::v4(), 8080), acceptor(io_context, endpoint) {}

  void start() {
    accept();

    io_context.run();
  }
};

int main() {
  WebServer web_server;

  web_server.start();
}
