#include <iostream>
#include <string>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "gen-cpp/helloService.h" //New
#include "gen-cpp/hello_types.h"

int main(){
    
    //Thrift socket 

    std::shared_ptr<apache::thrift::transport::TSocket> socket (new apache::thrift::transport::TSocket("localhost", 1234));

    //Thrift transport
    //Use a TBufferedTransport -> Transport act as a buffer for storing data rather than reading/writing manually?

    std::shared_ptr<apache::thrift::transport::TTransport> transport (new apache::thrift::transport::TBufferedTransport(socket));

    //Thrift protocol

    std::shared_ptr<apache::thrift::protocol::TProtocol> protocol (new apache::thrift::protocol::TBinaryProtocol(transport));

    //Instantiate service

    helloServiceClient client(protocol); //New

    //Try Loop to open socket, call hello_func() and add(), return 0 when done 

   try {
      
      //Open Transport Layer?
      transport->open(); 

      //Ping sends one package to test connection?
      client.ping();
      std::cout << "ping()" << std::endl; 

      //Hello Block

      



      //AddBlock

      //Close Transport Layer
      transport->close();

      return 0;


   } catch(apache::thrift::transport::TException& tx){
       std::cout << "ERROR" << tx.what() << std::endl;
       return 1;
   }
}