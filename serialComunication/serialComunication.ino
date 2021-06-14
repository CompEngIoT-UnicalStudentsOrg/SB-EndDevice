String command;
 
void setup() {
    Serial.begin(9600); 
}
 
void loop() {
    if(Serial.available()){
        command = Serial.readStringUntil('\n');
         
        if(command.equals("init")){
            Serial.println("Command init");
            //initialize();
        }
        else if(command.equals("send")){
          Serial.println("sendMessage command");
            //send_message();
        }
        else if(command.equals("data")){
          Serial.println("get data command");
            //get_data();
        }
        else if(command.equals("reboot")){
          Serial.println("Reboot command");
            //reboot();
        }
        else{
            Serial.println("Invalid command");
        }
    }
}
