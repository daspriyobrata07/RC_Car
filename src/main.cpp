#include <Arduino.h>
#include <IRremote.hpp>

// IR Receiver
#define IR_RECEIVE_PIN 2

// Remote button commands
#define CMD_FORWARD 0x46
#define CMD_BACKWARD 0x15
#define CMD_STOP 0x40
#define CMD_LEFT 0x44
#define CMD_RIGHT 0x43

// L298N Motor Driver
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// Motor Functions
void forward()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void backward()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void stopCar()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void turnLeft()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void turnRight()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

// Setup
void setup()
{
    Serial.begin(9600);

    // Motor control pins
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    // Start with motors stopped
    stopCar();

    // Start IR receiver
    IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

    Serial.println("RC Car Ready");
}

// Loop
void loop()
{
    if (IrReceiver.decode())
    {
        uint8_t command = IrReceiver.decodedIRData.command;

        Serial.print("Command: 0x");
        Serial.println(command, HEX);

        switch (command)
        {
        case CMD_FORWARD:
            Serial.println("FORWARD");
            forward();
            break;

        case CMD_BACKWARD:
            Serial.println("BACKWARD");
            backward();
            break;

        case CMD_LEFT:
            Serial.println("LEFT");
            turnLeft();
            break;

        case CMD_RIGHT:
            Serial.println("RIGHT");
            turnRight();
            break;

        case CMD_STOP:
            Serial.println("STOP");
            stopCar();
            break;

        default:
            Serial.println("UNKNOWN COMMAND");
            break;
        }

        IrReceiver.resume();
    }
}