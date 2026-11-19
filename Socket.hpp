#ifndef Socket_hpp
#define Socket_hpp

//will be using windows libraries here since i am doing this in windows
#include <stdio.h>
#include <ws2tcpip.h>
#include <winsock2.h>
namespace HDE
{
    class Socket{
        private:
        struct sockaddr_in address;
        SOCKET sock;
        int connection;
        public:
         Socket(int domain,int service,int protocol,int port,u_long interfaceI);
         //the equal 0 is to symbolize that it has no body the return type is void
         //also since this is really my first serious cpp project migt do some explaining for myself
         //cpp doesnt have functions as virtual by default so the compiler uses static dispatch so it calls the method based on the compile time pointer typeand ignores polymorfism

         virtual int connect_network(SOCKET sock, struct sockaddr_in address)=0;

         void test_connection(int);

         struct sockaddr_in get_address();
         SOCKET get_sock();
         int get_connection();

    };

}

#endif