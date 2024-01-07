 #include <stdio.h>
#include <stdbool.h>
#define MAX_PARKING_SPACES 10
typedef struct {
 bool isOccupied;
 char licensePlate[15];
} ParkingSpace;
typedef struct {
 ParkingSpace spaces[MAX_PARKING_SPACES];
} ParkingLot;
void initializeParkingLot(ParkingLot *parkingLot) {
 for (int i = 0; i < MAX_PARKING_SPACES; i++) {
 parkingLot->spaces[i].isOccupied = false;
 }
}
void displayParkingLotStatus(ParkingLot *parkingLot) {
 printf("Parking Lot Status:\n");
 for (int i = 0; i < MAX_PARKING_SPACES; i++) {
 printf("Space %d: %s\n", i + 1, parkingLot->spaces[i].isOccupied ? 
"Occupied" : "Vacant");
 }
}
int parkCar(ParkingLot *parkingLot, char licensePlate[15]) {
 for (int i = 0; i < MAX_PARKING_SPACES; i++) {
 if (!parkingLot->spaces[i].isOccupied) {
 parkingLot->spaces[i].isOccupied = true
[1/4, 21:01] Trivsrao~: strcpy(parkingLot->spaces[i].licensePlate, licensePlate);
 printf("Car with license plate %s parked in space %d.\n", licensePlate, i +
1);
 return i; // Return the parking space index
 }
 }
 printf("Sorry, the parking lot is full.\n");
 return -1; // Return -1 if parking is unsuccessful
}
void vacateParkingSpace(ParkingLot *parkingLot, int spaceIndex) {
 if (spaceIndex >= 0 && spaceIndex < MAX_PARKING_SPACES) {
 parkingLot->spaces[spaceIndex].isOccupied = false;
 printf("Parking space %d vacated.\n", spaceIndex + 1);
 } else {
 printf("Invalid parking space index.\n");
 }
}
int main() {
 ParkingLot parkingLot;
 initializeParkingLot(&parkingLot)
 displayParkingLotStatus(&parkingLot);
 int spaceIndex = parkCar(&parkingLot, "ABC123");
 if (spaceIndex != -1) {
 displayParkingLotStatus(&parkingLot);
 }
 vacateParkingSpace(&parkingLot, spaceIndex);
 displayParkingLotStatus(&parkingLot);
 return 0;
}
