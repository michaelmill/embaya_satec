//---------------------------------------------------------------------------;
//
//---------------------------------------------------------------------------;

void error (const char *msg) {

   perror(msg);
   exit(0);
}

//---------------------------------------------------------------------------;
//
//---------------------------------------------------------------------------;

int c_satec_network_connect (struct c_dlms_adk_interface *c) {

   int                sockfd, n;
   struct sockaddr_in serv_addr;
   struct hostent    *server;

   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0) {
      error("ERROR opening socket");
   }
   server = gethostbyname(c->host);

   if (server == NULL) {
      fprintf(stderr, "ERROR, no such host\n");
      exit(0);
   }
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *) server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(c->port);

   if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
      error("ERROR connecting");
   }
   n = write(sockfd, c->msg, strlen(c->msg));
   if (n < 0) {
      error("ERROR writing to socket");
   }
   //printf ("%i\n", 104);
   n = read(sockfd, c->ret, 255);
   if (n < 0) {
      error("ERROR reading from socket");
   }
   printf("%s\n", c->ret);
   close(sockfd);

   return 1;
}
