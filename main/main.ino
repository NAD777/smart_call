#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,20,2);
String *time_change;
int btgr=5;
int btbl=4;
int btye=3;
int btwh=2;
int j=0;
int size=0;
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
  for(int i=0;i<size;i++)
  {
    Serial.print(time_change[i]);
    Serial.print("\n");
  } 
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
  size=n*2;
  time_change=new String[n*2]; 
  delay(300);
   lcd.clear();
  // screen(0,0,1);
   screen(2,0,"time");
   screen(0,1,"00:00-00:00");
   
   for(int i=0;i<n;i++)
   {
    String s="00:00",s1="00:00";
    int ch10=0,ch1=0,min10=0,min1=0;
    int h10=0,h1=0,m10=0,m1=0;
    lcd.clear();
    screen(0,0,i+1);
    screen(inden(i+1)+1,0,"time");
    screen(0,1,s);
    screen(5,1,"-");
    screen(6,1,s1);
    //////////////////////////////////////////////////////
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
        screen(5,1,"-");
        screen(6,1,s1);
        
        delay(100);
      }
      
      if(click(btye))
      {
        ch1++;
          if(ch1>=10)
          {
            ch1-=10;
            ch10++;
          }
          if(ch10*10+ch1>=24)
          {
            ch10=0;
            ch1=0; 
          }
        s[1]=char(ch1+48);
        s[0]=char(ch10+48);
        lcd.clear();
        screen(0,0,i+1);
        screen(inden(i+1)+1,0,"time");
        screen(0,1,s);
        screen(5,1,"-");
        screen(6,1,s1);
        
        delay(100);
      }
    }
    time_change[j]=s;
    j++;
    delay(300);
      //////////////////////////////////////////////////////
      while(!click(btgr))
    {
      if(click(btwh))
      {
        m1++;
          if(m1>=10)
          {
            m1-=10;
            m10++;
          }
          if(m10>=6)
          {
            m10=0;
            m1=0; 
          }
        s1[4]=char(m1+48);
        s1[3]=char(m10+48);
        lcd.clear();
        screen(0,0,i+1);
        screen(inden(i+1)+1,0,"time");
        screen(0,1,s);
        screen(5,1,"-");
        screen(6,1,s1);
        
        delay(100);
      }
      if(click(btye))
      {
        h1++;
          if(h1>=10)
          {
            h1-=10;
            h10++;
          }
          if(h10*10+h1>=24)
          {
            h10=0;
            h1=0; 
          }
        s1[1]=char(h1+48);
        s1[0]=char(h10+48);
        lcd.clear();
        screen(0,0,i+1);
        screen(inden(i+1)+1,0,"time");
        screen(0,1,s);
        screen(5,1,"-");
        screen(6,1,s1);
        delay(100);
      }
      //////////////////////////////////////////////////////////
    }
    time_change[j]=s1;
    j++;
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
