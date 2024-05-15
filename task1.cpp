#include <iostream>
#include <bitset>

constexpr int MAX_STUDENTS = 64;

void displayMenu()
{
    std::cout << "1. Mark attendance\n";
    std::cout << "2. Clear attendance\n";
    std::cout << "3. Attendance status\n";
    std::cout << "4. Toggle attendance\n";
    std::cout << "5. Exit\n";
}

void markAttendance(bool attendance[], int studentNum)
{
    attendance[studentNum] = true;
    std::cout << "Attendance set for student " << studentNum << std::endl;
}

void clearAttendance(bool attendance[], int studentNum)
{
    attendance[studentNum] = false;
    std::cout << "Attendance cleared for student " << studentNum << std::endl;
}

void displayAttendanceStatus(bool attendance[])
{
    int presentCount = 0;
    for (int i = 0; i < MAX_STUDENTS; ++i)
    {
        if (attendance[i])
        {
            ++presentCount;
        }
    }
    int absentCount = MAX_STUDENTS - presentCount;
    std::cout << "Present students: " << presentCount << std::endl;
    std::cout << "Absent students: " << absentCount << std::endl;
}

void toggleAttendance(bool attendance[], int studentNum)
{
    attendance[studentNum] = !attendance[studentNum];
    std::cout << "Attendance toggled for student " << studentNum << std::endl;
}

int main()
{
    bool attendanceRecord[MAX_STUDENTS] = {false};
    int choice;

    while (true)
    {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int studentNum;
            std::cout << "Enter student number (0-" << (MAX_STUDENTS - 1) << ") to mark present: ";
            std::cin >> studentNum;
            if (studentNum >= 0 && studentNum < MAX_STUDENTS)
            {
                markAttendance(attendanceRecord, studentNum);
            }
            else
            {
                std::cout << "Invalid student number! Please enter a number between 0 and " << (MAX_STUDENTS - 1) << ".\n";
            }
            break;
        }
        case 2:
        {
            int studentNum;
            std::cout << "Enter student number (0-" << (MAX_STUDENTS - 1) << ") to mark absent: ";
            std::cin >> studentNum;
            if (studentNum >= 0 && studentNum < MAX_STUDENTS)
            {
                clearAttendance(attendanceRecord, studentNum);
            }
            else
            {
                std::cout << "Invalid student number! Please enter a number between 0 and " << (MAX_STUDENTS - 1) << ".\n";
            }
            break;
        }
        case 3:
            displayAttendanceStatus(attendanceRecord);
            break;
        case 4:
        {
            int studentNum;
            std::cout << "Enter student number (0-" << (MAX_STUDENTS - 1) << ") to toggle attendance: ";
            std::cin >> studentNum;
            if (studentNum >= 0 && studentNum < MAX_STUDENTS)
            {
                toggleAttendance(attendanceRecord, studentNum);
            }
            else
            {
                std::cout << "Invalid student number! Please enter a number between 0 and " << (MAX_STUDENTS - 1) << ".\n";
            }
            break;
        }
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice! Please select a valid option.\n";
        }
    }

    return 0;
}
