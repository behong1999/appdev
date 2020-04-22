#include <stdio.h>
#include <i386-linux-gnu/curl/curl.h>
#include "comm.h"

void sendpost(char *url, char *post){
	CURL *curl;
	
	CURLcode res;
	//This function must be called at least once within a program
	curl_global_init(CURL_GLOBAL_ALL);
	
	//This function must be the first function to call, 
	//and it returns a CURL easy handle that you must use 
	//as input to other functions in the easy interface.
	curl = curl_easy_init();
	
	if(curl){
		curl_easy_setopt(curl,CURLOPT_URL,url);
		curl_easy_setopt(curl,CURLOPT_POSTFIELDS,post);
		res = curl_easy_perform(curl);
		if(res!=CURLE_OK){
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
							curl_easy_strerror(res));
		}
		//This function must be called when the operation is completed
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
}
