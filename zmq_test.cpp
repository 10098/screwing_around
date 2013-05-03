#include <zmq.hpp>
#include <cstring>
#include <cstdio>

void zmq_server();
void zmq_client();

void myf(void* p, void*){ free(p); }
int main(int argc, char **argv)
{
	if(argc > 1) {
		if(argv[1][0] =='c') zmq_client();
		else zmq_server();
	}	
	return 0;
}

void zmq_client()
{
	zmq::context_t ctx(1);
	zmq::socket_t sock(ctx, ZMQ_REP);
	char *m = (char*)malloc(10);
	strcpy(m, "mydata");
	zmq::message_t msg;
	//strcpy((char*)msg.data(), "mydata");

	sock.setsockopt(ZMQ_IDENTITY, "myclient", strlen("myclient"));
	sock.connect("tcp://127.0.0.1:6699");
   printf("LISTENING!\n");
   sock.recv(&msg);
   printf("%s\n", msg.data());
   msg.rebuild(m, 10, myf, NULL);
	sock.send(msg);
}

void zmq_server()
{
   char *i = (char*)malloc(8);
   strcpy(i, "myclient");
	zmq::context_t ctx(1);
	zmq::socket_t sock(ctx, ZMQ_ROUTER);
	zmq::message_t msg;
   zmq::message_t id(i, 8, myf, NULL);	
	sock.bind("tcp://*:6699");
   getc(stdin);
   printf("SENDING!\n");
   sock.send(id, ZMQ_SNDMORE);
   id.rebuild();
   sock.send(id, ZMQ_SNDMORE);
   char *m = (char*)malloc(10);
   strcpy(m, "HEY!");
   msg.rebuild(m, 10, myf, NULL);
   sock.send(msg);
   printf("RECEIVING!\n");
   sock.recv(&id);
   printf("%s\n", (char*)id.data());
   sock.recv(&msg);
   sock.recv(&msg);
   printf("%s\n", (char*)msg.data());
}

