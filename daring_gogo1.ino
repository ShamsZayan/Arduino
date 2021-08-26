// C++ code
using namespace std;
unsigned long time=0;
int ledPin =13;
String password;
String truePassword;
void setup()
{
  
  Serial.begin(9600);
  pinMode(13, OUTPUT);
   Serial.println("Enter your Password:");
  //stop the execution of program until user enter input as serial.available() return number of entered bytes
  while(Serial.available() == 0){}
   truePassword=Serial.readString();
// Prepare the character array inorder to convert truePassword string to char array 
char char_array[truePassword.length() + 1];
// Copy data in truePassword string to char array 
truePassword.toCharArray(char_array, truePassword.length() + 1);
  //copy the address of constant char array to pointer inorder to shift the pointer along all elements of char array 
  char* p_pass=&char_array[0];
  while(*p_pass!='\0' ) {
    //check if element is alphapet or number
    if(isalpha(*p_pass)){
      //check if element is uppercase alphapet or lowercase alphapet
      if(*p_pass>='A'&&*p_pass<='Z')
  * p_pass =((( * p_pass - 'A') + 1) % 26) + 'A';
      else if(*p_pass>='a'&&*p_pass<='z')
        * p_pass =((( * p_pass - 'a') + 1) % 26) + 'a';}
    else if(isdigit(*p_pass)){
    * p_pass =((( * p_pass - '0') + 1) % 10) + '0';
    }
     p_pass++;
  // do something with c
}
  //assign the modified password to truePassword string 
   truePassword=char_array;
  //take the new password from the user
   Serial.println("Enter your Password: again");
  while(Serial.available() == 0){}
   password=Serial.readString();
}

 
    
void loop()
{
  //check if enterd password is same as the modified truePassword
  if(password.compareTo(truePassword)==0){
    //modify truePassword if enterd password is true
  char char_array[truePassword.length() + 1]; 
truePassword.toCharArray(char_array, truePassword.length() + 1);
  char*p_pass=&char_array[0];
  while(*p_pass!='\0' ) {
  if(isalpha(*p_pass)){
      if(*p_pass>='A'&&*p_pass<='Z')
  *p_pass =((( * p_pass - 'A') + 1) % 26) + 'A';
      else if(*p_pass>='a'&&*p_pass<='z')
        * p_pass =((( * p_pass - 'a') + 1) % 26) + 'a';}
    else if(isdigit(*p_pass)){
    *p_pass =((( * p_pass - '0') + 1) % 10) + '0';
    }
     p_pass++;
}
    truePassword=char_array;
    //make led on for 3 seconds
    digitalWrite(13, HIGH);
  delay(3000); // Wait for 3000 millisecond(s)
  digitalWrite(13, LOW);
  }else{
    // truepassword willnot modified if entered password is wrong
    for(int i=0;i<3;i++){
 //make led blink for 3 seconds
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
    }
  }
 Serial.println("Enter your Password Again: ");
        while(Serial.available() == 0){}
    password=Serial.readString();
}