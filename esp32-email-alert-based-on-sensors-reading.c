#include <stdio.h> // Include I/O for email alert logs

int main(void) { // Entry
  printf("ESP32 Email Alert Based on Sensors Reading\n"); // Title
  printf("Read sensor values and compare against thresholds\n"); // Check
  printf("On exceed, send email via SMTP or web API\n"); // Alert
  return 0; // Exit
} // End main
