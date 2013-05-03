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
	zmq::socket_t sock(ctx, ZMQ_REQ);
	char *m = (char*)malloc(10);
	strcpy(m, "mydata");
	zmq::message_t msg(m, 10, myf, NULL);
	//strcpy((char*)msg.data(), "mydata");

	sock.setsockopt(ZMQ_IDENTITY, "myclient", strlen("myclient"));
	sock.connect("tcp://127.0.0.1:6699");
	sock.send(msg);
}

void zmq_server()
{
	zmq::context_t ctx(1);
	zmq::socket_t sock(ctx, ZMQ_ROUTER);
	zmq::message_t msg;
	
	sock.bind("tcp://*:6699");
	sock.recv(&msg);
	printf("%s\n", (char*)msg.data());
	int64_t m=34856;
	size_t s = sizeof(m);
	sock.getsockopt(ZMQ_RCVMORE, &m, &s); 
	printf("%d\n", m);
	zmq::message_t body;
	sock.recv(&body);
	sock.getsockopt(ZMQ_RCVMORE, &m, &s); 
	printf("%d\n", m);
	printf("%s\n",(char*)body.data());
	sock.recv(&body);
	sock.getsockopt(ZMQ_RCVMORE, &m, &s); 
	printf("%d\n", m);
	printf("%s\n",(char*)body.data());


}

