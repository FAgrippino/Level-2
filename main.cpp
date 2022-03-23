#include "MQTTClient.h"
#include <iostream>
#include <vector>

int main (void){

    MQTTClient cliente1("robot1");

    cliente1.connect("127.0.0.1", 1883, "user", "vdivEMMN3SQWX2Ez");
    int var1 = cliente1.isConnected();
    if (!var1) {
        std::cout << "Connection Error" << "\n";
        return 1;
    }

    cliente1.subscribe("robot1/motor[1]/voltage");
    
    while (1) {
        std::vector<MQTTMessage> mensaje = cliente1.getMessages();
        for (unsigned int i=0; i < mensaje.size(); i++){
            for (std::vector<char>::iterator j = mensaje[i].payload.begin(); j != mensaje[i].payload.end(); j++)
            std::cout << (float)*j << ", ";       
        }
        std::cout << "\n";
    }
    

    return 0;
}