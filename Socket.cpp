#include "Socket.hpp"


//default constructor
HDE::Socket::Socket(int domain, int service,int protocol,int port,u_long interfaceI){
   
    address.sin_family= domain;
    //the reson you use htons in this is because with an int you are passing to the network little endian byte order while htons translates this to big endian
    address.sin_port=htons(port);
    //now we will hav to pass our ip address
    //after i got the name interface i learned that windows actually throws an error for duplicate variable types
    //since windows has this macro #Define interface struct since C++ doest have interfaces so in this case the compiler was baically reading u_long struct 
    address.sin_addr.s_addr = htonl(interfaceI);
     //not declaring the connection here in the onstuctor since i will be needing this again 
    //here with this function we are not getting an integer but rather a socket object
    sock = socket(domain,service,protocol);
    connection=connect_network(sock,address);
}

void HDE::Socket::test_connection(int item_to_test){
        if(item_to_test < 0){

            perror("Failed to connect");

            exit(EXIT_FAILURE);

        }
}
struct sockaddr_in HDE::Socket::get_address(){
    return address;

}
SOCKET HDE::Socket::get_sock(){
    return sock;
}

int HDE::Socket::get_connection(){
    return connection;
}


