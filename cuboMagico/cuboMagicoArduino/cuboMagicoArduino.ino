#include <MadgwickAHRS.h>

#include <BMI160.h>
#include <CurieImu.h>
Madgwick filter; // initialise Madgwick object
int16_t ax, ay, az;
int16_t gx, gy, gz;
float yaw;
float pitch;
float roll;
int factor = 800; // variable by which to divide gyroscope values, used to control sensitivity
// note that an increased baud rate requires an increase in value of factor

int calibrateOffsets = 1; // int to determine whether calibration takes place or not


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
CurieImu.initialize();
if (calibrateOffsets==1){
  while(!Serial);
   // use the code below to calibrate accel/gyro offset values
    Serial.println("Internal sensor offsets BEFORE calibration...");
    Serial.print(CurieImu.getXAccelOffset()); Serial.print("\t");
    Serial.print(CurieImu.getYAccelOffset()); Serial.print("\t");
    Serial.print(CurieImu.getZAccelOffset()); Serial.print("\t");
    Serial.print(CurieImu.getXGyroOffset()); Serial.print("\t");
    Serial.print(CurieImu.getYGyroOffset()); Serial.print("\t");
    Serial.print(CurieImu.getZGyroOffset()); Serial.print("\t");
    Serial.println("");

    // To manually configure offset compensation values, use the following methods instead of the autoCalibrate...() methods below
    //    CurieIMU.setGyroOffset(X_AXIS, 220);
    //    CurieIMU.setGyroOffset(Y_AXIS, 76);
    //    CurieIMU.setGyroOffset(Z_AXIS, -85);
    //    CurieIMU.setAccelerometerOffset(X_AXIS, -76);
    //    CurieIMU.setAccelerometerOffset(Y_AXIS, -235);
    //    CurieIMU.setAccelerometerOffset(Z_AXIS, 168);

    //IMU device must be resting in a horizontal position for the following calibration procedure to work correctly!

    Serial.print("Starting Gyroscope calibration...");
    //CurieImu.autoCalibrateGyroOffset();
   CurieImu.setXGyroOffset(140);
   CurieImu.setYGyroOffset(128);
   CurieImu.setZGyroOffset(16);
    Serial.println(" Done");
    Serial.print("Starting Acceleration calibration...");
    CurieImu.autoCalibrateXAccelOffset (0);
    CurieImu.autoCalibrateYAccelOffset(0);
    CurieImu.autoCalibrateZAccelOffset(1);
    Serial.println(" Done");

    Serial.println("Internal sensor offsets AFTER calibration...");
    Serial.print(CurieImu.getXAccelOffset()); Serial.print("\t");
    Serial.print(CurieImu.getYAccelOffset()); Serial.print("\t");
    Serial.print(CurieImu.getZAccelOffset()); Serial.print("\t");
    Serial.print(CurieImu.getXGyroOffset()); Serial.print("\t");
    Serial.print(CurieImu.getYGyroOffset()); Serial.print("\t");
    Serial.print(CurieImu.getZGyroOffset()); Serial.print("\t");
    Serial.println("");
}
}

void loop() {
  // put your main code here, to run repeatedly:
// read raw accel/gyro measurements from device
 CurieImu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  // use function from MagdwickAHRS.h to return quaternions
  filter.updateIMU(gx / factor, gy / factor, gz / factor, ax, ay, az);

  // functions to find yaw roll and pitch from quaternions
  yaw = filter.getYaw();
  roll = filter.getRoll();
  pitch = filter.getPitch();
 
  // print gyro and accel values for debugging only, comment out when running Processing
  /*
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.print(gz); Serial.print("\t");
  Serial.println("");
  */

  if (Serial.available() > 0) {
    int val = Serial.read();
    if (val == 's') { // if incoming serial is "s"
      Serial.print(yaw);
      Serial.print(","); // print comma so values can be parsed
      Serial.print(pitch);
      Serial.print(","); // print comma so values can be parsed
      Serial.println(roll);
    }
  }
}
