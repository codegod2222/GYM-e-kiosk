#include "onlinePayment.h"

template <typename T>
std::string to_string_best(const T& t) 
{ 
    std::string str{ std::to_string(t) };     
    int offset{ 1 };     
    if (str.find_last_not_of('0') == str.find('.')) { 
        offset = 0; 
    }     
    str.erase(str.find_last_not_of('0') + offset, std::string::npos);      
    return str; 
}

static size_t WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct* mem = (struct MemoryStruct*)userp;

    char* ptr = (char*)realloc(mem->memory, mem->size + realsize + 1);
    if (ptr == NULL) {
        /* out of memory! */
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

std::string makeTransaction(float _amount, std::string _description, PAYMENT_METHOD _payment, std::string _mail, std::string _name) {
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();

    struct MemoryStruct chunk;
    chunk.memory = (char*)malloc(1);
    chunk.size = 0;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, "https://secure.tpay.com/api/gw/75f86137a6635df826e3efe2e66f7c9a946fdde1/transaction/create");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Cookie: trlang=EN; __cfduid=d52db2caa022688fae5307f78ef2048121591898685");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        std::string amount = to_string_best(_amount);
        std::string payment = std::to_string(_payment);
        std::string dataPom = "{"
            "\n  \"id\": 1010,"
            "\n  \"amount\": " + amount + ","
            "\n  \"description\": \"" + _description + "\","
            "\n  \"md5sum\": \"" + md5("1010" + amount + "demo") + "\","
            "\n  \"group\": " + payment + ","
            "\n  \"merchant_description\": \"Najlepsza siłownia na świecie\","
            "\n  \"language\": \"pl\","
            "\n  \"email\": \"" + _mail + "\","
            "\n  \"name\": \"" + _name + "\","
            "\n  \"api_password\": \"p@$$w0rd#@!\""
            "\n"
            "}";
        const char* data = dataPom.c_str();
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
        res = curl_easy_perform(curl);
    }
    curl_easy_cleanup(curl);
    nlohmann::json js = nlohmann::json::parse(chunk.memory);
   
    return js["url"];
}

std::string getTransactionStatus(std::string title) {
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();

    struct MemoryStruct chunk;
    chunk.memory = (char*)malloc(1);
    chunk.size = 0;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, "https://secure.tpay.com/api/gw/75f86137a6635df826e3efe2e66f7c9a946fdde1/transaction/get");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: text/plain");
        headers = curl_slist_append(headers, "Cookie: trlang=EN; __cfduid=d52db2caa022688fae5307f78ef2048121591898685");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        std::string dataPom = "{"
            "\n  \"title\": \"" + title + "\","
            "\n  \"api_password\": \"p@$$w0rd#@!\""
            "\n"
        "}";
        const char* data = dataPom.c_str();
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
        res = curl_easy_perform(curl);
}
curl_easy_cleanup(curl);

nlohmann::json js;
try {
    js = nlohmann::json::parse(chunk.memory);
}
catch (nlohmann::detail::type_error err) {

}
    
    return js["status"];

}