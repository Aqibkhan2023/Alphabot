int motor1enable = 5;
int motor1forward = A0;
int motor1backward = A1;

int motor2enable = 6;
int motor2forward = A3;
int motor2backward = A2;

char command;

void setup()
{
  Serial.begin(9600);
  pinMode(motor1enable, OUTPUT);
  pinMode(motor1forward, OUTPUT);
  pinMode(motor1backward, OUTPUT);

  pinMode(motor2enable, OUTPUT);
  pinMode(motor2forward, OUTPUT);
  pinMode(motor2backward, OUTPUT);
}

void loop()
{

  if (Serial.available() > 0)
  {
    command = Serial.read();
    Serial.println(command);
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.
    //Serial.println(command);
    switch (command)
    {
    case 'F': //Forward
      forward();
      break;
    case 'B': //Backward
      back();
      break;
    case 'L': //Left
      left();
      break;
    case 'R': //Right
      right();
      break;
    }
  }
}


void forward()
{
  moveMotor1Forward();

  moveMotor2Forward();
}

void back()
{
  moveMotor1Backward();

  moveMotor2Backward();
}

void left()
{
  moveMotor1Backward();

  moveMotor2Forward();
}

void right()
{
  moveMotor1Forward();

  moveMotor2Backward();
}

void Stop()
{
  motor1Stop();
  motor2Stop();
}


void moveMotor1Forward()
{
  digitalWrite(motor1forward, HIGH);
  digitalWrite(motor1backward, LOW);
  analogWrite(motor1enable, 255);
}
void moveMotor2Forward()
{
  digitalWrite(motor2forward, HIGH);
  digitalWrite(motor2backward, LOW);
  analogWrite(motor2enable, 255);
}

void moveMotor1Backward()
{
  digitalWrite(motor1forward, LOW);
  digitalWrite(motor1backward, HIGH);
  analogWrite(motor1enable, 255);
}
void moveMotor2Backward()
{
  digitalWrite(motor2forward, LOW);
  digitalWrite(motor2backward, HIGH);
  analogWrite(motor2enable, 255);
}

void motor1Stop()
{

  digitalWrite(motor1forward, LOW);
  digitalWrite(motor1backward, LOW);
  analogWrite(motor1enable, 255);
}

void motor2Stop()
{
  digitalWrite(motor2forward, LOW);
  digitalWrite(motor2backward, LOW);
  analogWrite(motor2enable, 255);
}

