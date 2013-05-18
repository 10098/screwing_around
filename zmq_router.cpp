#include <zmq.hpp>
#include <iostream>
#include <cstring>

int main(int argc, char *argv[])
{
   if(argc >= 3)
   {
      char mode = argv[1][0];
      char *addr = argv[2];
      
      zmq::context_t ctx(1);
      zmq::socket_t sck(ctx, ZMQ_ROUTER);

      if(mode == 'b')
      {
         sck.setsockopt(ZMQ_IDENTITY, addr, strlen(addr));
         sck.bind(addr);
         zmq::message_t msg;
         while(1){
            while(sck.recv(&msg, ZMQ_NOBLOCK)) {
               std::cout << std::string((const char*)msg.data()) << ": ";
               sck.recv(&msg);
               sck.recv(&msg);
               std::cout << std::string((const char*)msg.data()) << std::endl;
            }
         }
      }
      else if(mode == 'c')
      {
         sck.setsockopt(ZMQ_IDENTITY, "cli", strlen("cli")+1);
         sck.connect(addr);
         zmq::message_t msg;
         while(1) {
            msg.rebuild(strlen(addr));
            memcpy(msg.data(), addr, strlen(addr));
            sck.send(msg, ZMQ_SNDMORE);
            msg.rebuild();
            sck.send(msg, ZMQ_SNDMORE);
            std::string message = "msg! msg!";
            msg.rebuild(message.size());
            memcpy(msg.data(), message.c_str(), message.size());
            sck.send(msg);
         }
      }
   }
   else
   {
      std::cout << "usage: rtr [b|c] [addr]" << std::endl; 
   }

   return 0;
}
