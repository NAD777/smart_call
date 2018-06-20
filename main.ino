#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,20,2);
String *time_change;
int btgr=5;
int btbl=4;
int btye=3;
int btwh=2;
int inden(int n)
{
  int ans=0;
  while(n)
  {
   n/=10;
   ans++; 
  }
  return ans;
}
bool click(int pin)
{
  if(digitalRead(pin)==HIGH)
    return true;
   return false;
}
void screen(int x, int y, String s);
void screen(int x, int y, int s);
void setup() 
{
  pinMode(btgr,INPUT);
  pinMode(btbl,INPUT);
  pinMode(btye,INPUT);
  pinMode(btwh,INPUT);
  String str = "Mac one love!";
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  screen(0,0,str);
  set();
}
void set()
{
  int n=0;
  lcd.clear();
  screen(0,0,"Number of changes");
  screen(0,1,n);
  while(!click(btgr))
  {
    if(click(btwh))
      {
        n++;
        lcd.clear();
        screen(0,0,"Number of changes");
        screen(0,1,n);
        delay(100);
      }
  }
  time_change=new String[n]; 
  delay(300);
   lcd.clear();
  // screen(0,0,1);
   screen(2,0,"time");
   screen(0,1,"00:00");
   for(int i=0;i<n;i++)
   {
    String s="00:00";
    int ch10=0,ch1=0,min10=0,min1=0;
    lcd.clear();
    screen(0,0,i+1);
    screen(inden(i+1)+1,0,"time");
    screen(0,1,s);
    while(!click(btgr))
    {
      if(click(btwh))
      {
        min1++;
          if(min1>=10)
          {
            min1-=10;
            min10++;
          }
          if(min10>=6)
          {
            min10=0;
            min1=0; 
          }
        s[4]=char(min1+48);
        s[3]=char(min10+48);
        lcd.clear();
        screen(0,0,i+1);
        screen(inden(i+1)+1,0,"time");
        screen(0,1,s);
        Serial.print(i,' ');
        Serial.print(s);
        Serial.print('\n');
        delay(100);
      }
      
    }
    delay(300);
   }
}
  

void loop()
{
  
}

void screen(int x, int y, String s)
{
  
  lcd.setCursor(x,y);
  lcd.print(s);
}
void screen(int x, int y, int s)
{
  
  lcd.setCursor(x,y);
  lcd.print(s);
}
