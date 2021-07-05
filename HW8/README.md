## Timetable Program
### Basics
- Input the days and hours that should appear in the timetable (Start Day to End Day, Start Time to End Time) and managed by the user. Both days and hours are treated consecutively. For example, Monday to Friday, Monday to Saturday, 9:00 to 18:00, 10:00 to 20:00)
- Time is managed on an hourly basis.
- It offers three functions. (Input subject, Deleting subjects, Timetable status)
- The program does not terminate until you select Exit from the menu.
### Initiate
- Only once at startup, you are given the day and time of the week to organize the timetable.
- Current timetables and menus are always printed at the end of each function.
### Function
1. Input subject
- Enter subject name, professor name, classroom, credit, class time, day, start time
- Store subject names limited to 2 characters (only 2 characters long).
- If the subject has multiple lectures per week, it can be entered several times. (The input method can be implemented in many ways)
- If there is already a lecture at that time, it prints out an error message.
- If you already have the same subject, print out an error message.
- If the time is outside the scope of the timetable, it outputs an error message.
2. Delete subject
- Get the subject name by input and delete it from the timetable.
- While deletion, all lectures (different days and times) in the subject shall be deleted together.
- Be sure to get confirmation from the user before deleting.
- If you don't have a subject, print out an error message.
3. Timetable Status
- Shows the number of subjects registered, the total number of credits, the total lecture time, and the total vacancy time.
- If no subject is entered, output 'timetable empty'
