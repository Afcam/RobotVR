/**
 * @file UDP->c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-10
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "UDP.h"

/**
 * @brief 
 * 
 */
UDP *InitUDP(int Port)
{
    UDP *udp = malloc(sizeof(UDP));

    if ((udp->sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        printf("Could not create socket");
        return (0);
    }

    udp->server_addr.sin_addr.s_addr = INADDR_ANY;
    // udp->server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    udp->server_addr.sin_family = AF_INET;
    udp->server_addr.sin_port = htons(Port);
    bzero(&(udp->server_addr.sin_zero), 8);

    if (bind(udp->sock, (struct sockaddr *)&udp->server_addr,
             sizeof(struct sockaddr)) == -1)
    {
        printf("Could not bind socket");
        return (0);
    }

    udp->addr_len = sizeof(struct sockaddr);

    printf("\nUDPServer Waiting for client on port %d",Port);    // fflush(stdout);
    return udp;
}

/**
 * @brief 
 * 
//  */
char *ReadUDP(UDP *udp)
{

    // printf("\n(%s , %d) said : ", inet_ntoa(udp->client_addr.sin_addr),
    //        ntohs(udp->client_addr.sin_port));
    udp->bytes_read = recvfrom(udp->sock, udp->recv_data, 1024, 0,
                               (struct sockaddr *)&udp->client_addr, &udp->addr_len);

    udp->recv_data[udp->bytes_read] = '\0';

    // printf("\n(%s , %d) said : ", inet_ntoa(udp->client_addr.sin_addr),
    //        ntohs(udp->client_addr.sin_port));
    // printf("%s", udp->recv_data);
    // return udp->recv_data;
    fflush(stdout);
    return udp->recv_data;
}
