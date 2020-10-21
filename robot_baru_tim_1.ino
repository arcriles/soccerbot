#include <SoftwareSerial.h>// import the serial library
SoftwareSerial bluetooth(0, 1); // RXD, TXD
int BluetoothData; // the data given from Computer
//RODA
int m2kiri = 13;
int m1kiri = 12;
int skiri = 10;

int m1kanan = 11;
int m2kanan = 8 ;
int skanan = 9;

//HANDLING
int handle =6;
void setup()
{
  pinMode(m1kiri, OUTPUT); //RODA kiri
  pinMode(m2kiri, OUTPUT); //RODA kiri
  pinMode(skiri, OUTPUT); //KECEPATAN RODA kiri
  pinMode(m1kanan, OUTPUT); //RODA kanan
  pinMode(m2kanan, OUTPUT); //RODA kanan
  pinMode(skanan, OUTPUT); //KECEPATAN RODA kanan
  pinMode( 4, OUTPUT); //LED merah
  pinMode( 5, OUTPUT); //LED biru
  pinMode( 2, OUTPUT); //PENENDANG
  pinMode (handle, OUTPUT); //HANDLING
  digitalWrite(2, HIGH);
digitalWrite (handle, HIGH);


  bluetooth.begin(9600);
  bluetooth.println("Bluetooth READY!");
}
void loop()
{
  if (bluetooth.available()) 
  
    BluetoothData = bluetooth.read();{
    }
                    if (BluetoothData == '0')
    {
      digitalWrite(m1kiri, HIGH);
      digitalWrite(m2kiri, LOW);
      analogWrite(skiri, 0);

      digitalWrite(m1kanan, HIGH);
      digitalWrite(m2kanan, LOW);
      analogWrite(skanan, 0);

      digitalWrite(handle, HIGH);
    }
  if (BluetoothData == '1') //maju
  {
    digitalWrite(m1kiri, HIGH);
    digitalWrite(m2kiri, LOW);
    analogWrite(skiri, 200);

    digitalWrite(m1kanan, HIGH);
    digitalWrite(m2kanan, LOW);
    analogWrite(skanan, 200);

    digitalWrite(handle, HIGH);
  }

  if (BluetoothData == '2')//maju sprint
  {
    digitalWrite(m1kiri, HIGH);
    digitalWrite(m2kiri, LOW);
    analogWrite(skiri, 255);

    digitalWrite(m1kanan, HIGH);
    digitalWrite(m2kanan, LOW);
    analogWrite(skanan, 255);

    digitalWrite(handle, HIGH);
  }
  if (BluetoothData == '3') //kiri
  {
    digitalWrite(m1kiri, LOW);
    digitalWrite(m2kiri, HIGH);
    analogWrite(skiri, 200);

    digitalWrite(m1kanan, HIGH);
    digitalWrite(m2kanan, LOW);
    analogWrite(skanan, 200);

    digitalWrite(handle, LOW);
  }
  if (BluetoothData == '4') // mundur tanpa handle
  {
    digitalWrite(m1kiri, LOW);
    digitalWrite(m2kiri, HIGH);
    analogWrite(skiri, 255);

    digitalWrite(m1kanan, LOW);
    digitalWrite(m2kanan, HIGH);
    analogWrite(skanan, 255);

    digitalWrite(handle, HIGH);

  }
  if (BluetoothData == '5') // mundur
  {
    digitalWrite(m1kiri, LOW);
    digitalWrite(m2kiri, HIGH);
    analogWrite(skiri, 120);

    digitalWrite(m1kanan, LOW);
    digitalWrite(m2kanan, HIGH);
    analogWrite(skanan, 120);

    digitalWrite(handle, LOW);
  }

  if (BluetoothData == '7') //kanan
  {
    digitalWrite(m1kiri, HIGH);
    digitalWrite(m2kiri, LOW);
    analogWrite(skiri, 200);

    digitalWrite(m1kanan, LOW);
    digitalWrite(m2kanan, HIGH);
    analogWrite(skanan, 200);

    digitalWrite(handle, LOW);
  }
  if (BluetoothData == '8') //maju lambat
  {
    digitalWrite(m1kiri, HIGH);
    digitalWrite(m2kiri, LOW);
    analogWrite(skiri, 125);

    digitalWrite(m1kanan, HIGH);
    digitalWrite(m2kanan, LOW);
    analogWrite(skanan, 125);

    digitalWrite(handle, HIGH);
  }
 
  if (BluetoothData == 'A') //maju tendang
  {
    digitalWrite(m1kiri, HIGH);
    digitalWrite(m2kiri, LOW);
    analogWrite(skiri, 255);

    digitalWrite(m1kanan, HIGH);
    digitalWrite(m2kanan, LOW);
    analogWrite(skanan, 255);

    digitalWrite(handle, HIGH);
    delay (100);
    digitalWrite (2, LOW);
    delay (80);
    digitalWrite (2, HIGH);
  }
  if (BluetoothData == 'B') //tendang
  {
    digitalWrite (2, LOW);
    delay (80);
    digitalWrite (2, HIGH);

  }

  if (BluetoothData == 'X') //rebut bola
  { digitalWrite(m1kiri, HIGH);
    digitalWrite(m2kiri, LOW);
    analogWrite(skiri, 255);

    digitalWrite(m1kanan, HIGH);
    digitalWrite(m2kanan, LOW);
    analogWrite(skanan, 255);

    digitalWrite(handle, LOW);
  }
  if (BluetoothData == 'Z') //led merah
  {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
  if (BluetoothData == 'C') //led biru
  {
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  if (BluetoothData == 'Y') //diam handle menyala
  {
    digitalWrite(m1kiri, HIGH);
    digitalWrite(m2kiri, LOW);
    analogWrite(skiri, 0);

    digitalWrite(m1kanan, HIGH);
    digitalWrite(m2kanan, LOW);
    analogWrite(skanan, 0);

    digitalWrite(handle, LOW);

  }
}
