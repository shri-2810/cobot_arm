#include <Servo.h>

// Create Servo objects for each motor
Servo baseServo;       // Base rotation
Servo shoulderServo;   // Shoulder movement
Servo elbowServo;      // Elbow movement
Servo wristServo;      // Wrist movement
Servo armServo;        // Arm movement (between wrist and gripper)
Servo gripperServo;    // Gripper control

char lastCommand = '\0';  // Variable to store the last command

void setup() {
  // Attach servos to respective pins
  baseServo.attach(3);
  shoulderServo.attach(5);
  elbowServo.attach(6);
  wristServo.attach(9);
  armServo.attach(11);    // Attach arm motor to pin 11
  gripperServo.attach(10);

  Serial.begin(9600);  // Start serial communication for Bluetooth
  baseServo.write(90);  // Initialize base servo to stop position
  shoulderServo.write(90); // Initialize shoulder servo to stop position
  elbowServo.write(90);    // Initialize elbow servo to stop position
  wristServo.write(90);    // Initialize wrist servo to stop position
  armServo.write(90);      // Initialize arm servo to neutral position
  gripperServo.write(0);   // Initialize gripper to open position
}

void pickPosition() {
  // Move servos to pick position
  baseServo.write(90);         // Stop the base
  shoulderServo.write(45);      // Adjust shoulder
  elbowServo.write(90);         // Adjust elbow
  wristServo.write(45);         // Adjust wrist
  armServo.write(90);           // Set arm to neutral position
  delay(1000);

  gripperServo.write(180);      // Close gripper to pick object
  delay(1000);                  // Allow time to grip
}

void placePosition() {
  // Move servos to place position
  baseServo.write(90);         // Stop the base
  shoulderServo.write(90);      // Adjust shoulder
  elbowServo.write(45);         // Adjust elbow
  wristServo.write(90);         // Adjust wrist
  armServo.write(90);           // Set arm to neutral position
  delay(1000);

  gripperServo.write(0);        // Open gripper to release object
  delay(1000);                  // Allow time to release
}

void stopBase() {
  baseServo.write(90);  // Stop the base rotation (neutral position)
}

void stopShoulder() {
  shoulderServo.write(90);  // Stop shoulder movement (neutral position)
}

void stopElbow() {
  elbowServo.write(90);  // Stop elbow movement (neutral position)
}

void stopWrist() {
  wristServo.write(90);  // Stop wrist movement (neutral position)
}

void stopArm() {
  armServo.write(90);    // Stop arm movement (neutral position)
}

void stopGripper() {
  gripperServo.write(0);  // Open gripper (neutral position)
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the command from Bluetooth

    // Only process the command if it's different from the last one
    if (command != lastCommand) {
      lastCommand = command;  // Update lastCommand to the current one

      // Example commands for base and other servos
      switch (command) {
        // Base motor control
        case 'b':  // Rotate base left slowly
          baseServo.write(70);  // Adjust value to control rotation speed
          break;

        case 'n':  // Rotate base right slowly
          baseServo.write(110);  // Adjust value to control rotation speed
          break;

        case 'x':  // Stop base rotation
          stopBase();
          break;

        // Shoulder motor control
        case 's':  // Raise shoulder
          shoulderServo.write(110);
          break;

        case 'd':  // Lower shoulder
          shoulderServo.write(70);
          break;

        case 'y':  // Stop shoulder movement
          stopShoulder();
          break;

        // Elbow motor control
        case 'e':  // Raise elbow
          elbowServo.write(110);
          break;

        case 'c':  // Lower elbow
          elbowServo.write(70);
          break;

        case 'z':  // Stop elbow movement
          stopElbow();
          break;

        // Wrist motor control
        case 'w':  // Raise wrist
          wristServo.write(110);
          break;

        case 'q':  // Lower wrist
          wristServo.write(70);
          break;

        case 'u':  // Stop wrist movement
          stopWrist();
          break;

        // Arm motor control
        case 'a':  // Move arm to a specific position (example: raise arm)
          armServo.write(45);  // Adjust this angle as needed
          break;

        case 'r':  // Move arm back to neutral position
          armServo.write(90);  // Neutral position for arm
          break;

        case 't':  // Stop arm movement
          stopArm();
          break;

        // Gripper control
        case 'g':  // Close gripper
          gripperServo.write(180);
          break;

        case 'o':  // Open gripper
          gripperServo.write(0);
          break;

        case 'i':  // Stop gripper movement (open)
          stopGripper();
          break;

        // Commands for picking and placing
        case 'p':  // Command to pick
          pickPosition();
          delay(2000);  // Wait for the grip to stabilize
          break;

        case 'l':  // Command to place
          placePosition();
          delay(2000);  // Wait before repeating
          break;

        // Stop all servos
        case '':  // Stop all movements
          stopBase();      // Stop base rotation
          stopShoulder();  // Neutral position for shoulder
          stopElbow();     // Neutral position for elbow
          stopWrist();     // Neutral position for wrist
          stopArm();       // Neutral position for arm
          stopGripper();   // Neutral position for gripper
          break;
      }
    }
  }
}
