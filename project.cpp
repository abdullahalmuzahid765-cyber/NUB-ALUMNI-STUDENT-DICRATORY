#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/*  ==AUTO FILE CREATE== (FOR EVERYONE) */
void createFiles() {
    ofstream("students.txt", ios::app).close();
    ofstream("alumni.txt", ios::app).close();
    ofstream("opportunities.txt", ios::app).close();
    ofstream("messages.txt", ios::app).close();
    ofstream("connections.txt", ios::app).close();
    ofstream("activity_log.txt", ios::app).close();
    ofstream("career_timeline.txt", ios::app).close();
}


/*  Log Activity (Khadija Akter) */
void logActivity(string activity) {
    ofstream log("activity_log.txt", ios::app);
    log << activity << endl;
    log.close();
}

/*  STUDENT REGISTRATION (Khadija Akter) */
void studentRegistration() {
    ofstream file("students.txt", ios::app);

    string id, name, dept, email;
    cout << "Student ID: "; getline(cin, id);
    cout << "Name: "; getline(cin, name);
    cout << "Department: "; getline(cin, dept);
    cout << "Email: "; getline(cin, email);

    string interest = "General";
    file << id << "," << name << "," << dept << "," << email << "," << interest << endl;
    file.close();

    logActivity("Student Registered: " + id);
    cout << "Registration successful!\n";
}

/* --ALUMNI REGISTRATION -(Khadija Aker) */
void alumniRegistration() {
    ofstream file("alumni.txt", ios::app);

    string name, batch, prof, company, dept;
    cout << "Name: "; getline(cin, name);
    cout << "Batch: "; getline(cin, batch);
    cout << "Profession: "; getline(cin, prof);
    cout << "Company: "; getline(cin, company);
    cout << "Department: "; getline(cin, dept);

    file << name << "," << batch << "," << prof << "," << company << "," << dept << endl;
    file.close();

    logActivity("Alumni Registered: " + name);
    cout << "Alumni registered successfully!\n";
}

/* - ADD CAREER TIMELINE (Abdullah Al Muzahid) - */
void addCareerTimeline() {
    ofstream file("career_timeline.txt", ios::app);

    string name, year, position, company;
    cout << "Alumni Name: "; getline(cin, name);
    cout << "Year: "; getline(cin, year);
    cout << "Position: "; getline(cin, position);
    cout << "Company: "; getline(cin, company);

    file << name << "," << year << "," << position << "," << company << endl;
    file.close();

    logActivity("Career Timeline Added: " + name);
    cout << "Career timeline added successfully!\n";
}

/* == VIEW CAREER TIMELINE ==(Abdullah Al Muzahid) */
void viewCareerTimeline() {
    ifstream file("career_timeline.txt");
    string name, line;

    cout << "Enter Alumni Name: ";
    getline(cin, name);

    cout << "\n--- Career Path Timeline ---\n";

    while (getline(file, line)) {
        string aname, year, position, company;
        stringstream ss(line);

        getline(ss, aname, ',');
        getline(ss, year, ',');
        getline(ss, position, ',');
        getline(ss, company, ',');

        if (aname == name) {
            cout << year << " -> " << position
                 << " at " << company << endl;
        }
    }
    file.close();
}

/* - MENTORSHIP MATCH -(Abdullah Al Muzahid) */
void mentorshipMatch() {
    ifstream sread("students.txt");
    ifstream aread("alumni.txt");

    string studentID, line;
    string sid, sname, sdept, semail, sinterest;
    string aname, abatch, aprof, acomp, adept;
    bool studentFound = false;

    cout << "Enter Student ID: ";
    getline(cin, studentID);

    while (getline(sread, line)) {
        stringstream ss(line);
        getline(ss, sid, ',');
        getline(ss, sname, ',');
        getline(ss, sdept, ',');
        getline(ss, semail, ',');
        getline(ss, sinterest, ',');

        if (sid == studentID) {
            studentFound = true;
            break;
        }
    }

    if (!studentFound) {
        cout << "Student not found!\n";
        return;
    }

    while (getline(aread, line)) {
        stringstream as(line);
        getline(as, aname, ',');
        getline(as, abatch, ',');
        getline(as, aprof, ',');
        getline(as, acomp, ',');
        getline(as, adept, ',');

        if (sdept == adept || sinterest == aprof) {
            cout << "\nMentor Matched!\n";
            cout << "Name: " << aname << endl;
            cout << "Profession: " << aprof << endl;
            cout << "Company: " << acomp << endl;
            logActivity("Mentorship Matched for Student: " + studentID);
            return;
        }
    }

    cout << "No suitable mentor found.\n";
}

/* == POST OPPORTUNITY ==(Abdullah Al Muzahid) */
void alumniPostOpportunity() {
    ofstream file("opportunities.txt", ios::app);
    string title, company, type, deadline;

    cout << "Title: "; getline(cin, title);
    cout << "Company: "; getline(cin, company);
    cout << "Type: "; getline(cin, type);
    cout << "Deadline: "; getline(cin, deadline);

    file << title << "|" << company << "|" << type << "|" << deadline << endl;
    file.close();

    cout << "Opportunity posted!\n";
}

/*  VIEW OPPORTUNITIES (Abdullah Al Muzahid)  */
void studentViewOpportunities() {
    ifstream file("opportunities.txt");
    string line;

    cout << "\n--- Opportunities ---\n";
    while (getline(file, line))
        cout << line << endl;

    file.close();
}

/* ==VIEW ALUMNI DIRECTORY ==(Abdullah Al Muzahid) */
void viewAlumni() {
    ifstream file("alumni.txt");
    string line;

    cout << "\n--- Alumni Directory ---\n";
    while (getline(file, line))
        cout << line << endl;

    file.close();
}

/* == SEARCH ALUMNI==(Abdullah Al Muzahid)  */
void searchAlumni() {
    ifstream file("alumni.txt");
    string key, line;

    cout << "Search keyword: ";
    getline(cin, key);

    while (getline(file, line))
        if (line.find(key) != string::npos)
            cout << line << endl;

    file.close();
}

/* - SEND CONNECTION REQUEST -(Abdullah Al Muzahid) */
void sendConnection() {
    ofstream file("connections.txt", ios::app);
    string student, alumni;

    cout << "Student ID: "; getline(cin, student);
    cout << "Alumni Name: "; getline(cin, alumni);

    file << student << " -> " << alumni << endl;
    file.close();

    logActivity("Connection Request Sent");
    cout << "Connection request sent!\n";
}

/* -- MESSAGE SYSTEM -(Tasnim Oishe)- */
void sendMessage() {
    ofstream file("messages.txt", ios::app);
    string from, to, msg;

    cout << "From: "; getline(cin, from);
    cout << "To: "; getline(cin, to);
    cout << "Message: "; getline(cin, msg);

    file << from << "|" << to << "|" << msg << endl;
    file.close();

    cout << "Message sent!\n";
}

/* -View Message -(Tasnim Oishe) */
void viewMessages() {
    ifstream file("messages.txt");
    string line;

    cout << "\n--- Messages ---\n";
    while (getline(file, line))
        cout << line << endl;

    file.close();
}

/* -BACKUP -(Tasnim Oishe) */
void backupData() {

    string srcFile = "alumni.txt";
    string backupFile = "alumni_backup.txt";

    ifstream src(srcFile);
    if (!src.is_open()) {
        cout << "Error: Could not open " << srcFile << endl;
        return;
    }

    ofstream dest(backupFile);
    if (!dest.is_open()) {
        cout << "Error: Could not create " << backupFile << endl;
        src.close();
        return;
    }

    dest << src.rdbuf();

    src.close();
    dest.close();

    cout << "\nBackup completed successfully!\n";

    ofstream log("activity_log.txt", ios::app);
    log << "Backup done: " << srcFile << " -> " << backupFile << endl;
    log.close();

    cout << "Backup recorded in activity_log.txt\n";
    cout << "-----------------------------------\n";
}




/* - REPORT -(Tasnim Oishe) */
void generateReport() {
    string studentFile = "students.txt";
    string alumniFile = "alumni.txt";

    ifstream s(studentFile);
    ifstream a(alumniFile);

    if (!s.is_open()) {
        cout << "Error: Could not open " << studentFile << endl;
        return;
    }

    if (!a.is_open()) {
        cout << "Error: Could not open " << alumniFile << endl;
        return;
    }

    int sc = 0, ac = 0;
    string line;

    while (getline(s, line)) sc++;
    while (getline(a, line)) ac++;

    s.close();
    a.close();

    cout << "\n==============================\n";
    cout << "         NUB DIRECTORY REPORT         \n";
    cout << "==============================\n";
    cout << "Total Students: " << sc << endl;
    cout << "Total Alumni  : " << ac << endl;

    int totalPeople = sc + ac;
    if (totalPeople > 0) {
        double studentPercent = (sc * 100.0) / totalPeople;
        double alumniPercent = (ac * 100.0) / totalPeople;
        cout << "Percentage of Students: " << studentPercent << "%" << endl;
        cout << "Percentage of Alumni  : " << alumniPercent << "%" << endl;
    }

    ofstream log("activity_log.txt", ios::app);
    log << "Report Generated: Students=" << sc << ", Alumni=" << ac << endl;
    log.close();

    cout << "Report recorded in activity_log.txt\n";
    cout << "==============================\n";
}



/* == MAIN ==(FOR EVERYONE)*/
int main() {
    createFiles();

    int op;
    do {
        cout << "\n\n";
        cout << "====== Welcome To ======\n\n";
        cout << "NUB STUDENT ALUMNI DIRECTORY\n\n\n";

        cout << "1. Student Registration\n";
        cout << "2. Alumni Registration\n";
        cout << "3. Mentorship Match\n";
        cout << "4. Post Opportunity\n";
        cout << "5. View Opportunities\n";
        cout << "6. View Alumni Directory\n";
        cout << "7. Search Alumni\n";
        cout << "8. Send Connection Request\n";
        cout << "9. Send Message\n";
        cout << "10. View Messages\n";
        cout << "11. Backup Data\n";
        cout << "12. Generate Report\n";
        cout << "13. Add Career Timeline (Alumni)\n";
        cout << "14. View Career Timeline (Student)\n";
        cout << "0. Exit\n";
        cout << "Choice: ";

        cin >> op;
        cin.ignore();

        if (op == 1) studentRegistration();
        else if (op == 2) alumniRegistration();
        else if (op == 3) mentorshipMatch();
        else if (op == 4) alumniPostOpportunity();
        else if (op == 5) studentViewOpportunities();
        else if (op == 6) viewAlumni();
        else if (op == 7) searchAlumni();
        else if (op == 8) sendConnection();
        else if (op == 9) sendMessage();
        else if (op == 10) viewMessages();
        else if (op == 11) backupData();
        else if (op == 12) generateReport();
        else if (op == 13) addCareerTimeline();
        else if (op == 14) viewCareerTimeline();

    } while (op != 0);

    return 0;
}
