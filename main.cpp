#include <iostream>
#include <stdio.h>
#include <curl/curl.h>
#include "json.hpp"


using namespace std;
using json = nlohmann::json;

int main(void)
{
  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_DEFAULT);

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts");



    /* Perform the request, res will get the return code */
      /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();

  //================================================
  json j_string = res;

  // retrieve the string value
  auto cpp_string = j_string.get<std::string>();
  // retrieve the string value (alternative when an variable already exists)
  std::string cpp_string2;
  j_string.get_to(cpp_string2);

  // retrieve the serialized value (explicit JSON serialization)
  std::string serialized_string = j_string.dump();

  // output of original string
  std::cout << cpp_string << " == " << cpp_string2 << " == " << j_string.get<std::string>() << '\n';
  // output of serialized value
  std::cout << j_string << " == " << serialized_string << std::endl;

  return 0;
}
