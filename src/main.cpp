#include <server_http.hpp>
#include <iostream>

int main(){
  std::cout << "init\n";

  ServerHTTP::Server server{};
  server.mount_point = "assets";
  server.index_file = "index.html"; 

  std::string ip = "0.0.0.0";
  std::string port = "3000";
  server.init(ip.c_str(), port.c_str(), 10);
  server.listen();
  return 0;
}