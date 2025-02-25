#include <iostream> //VERY IMPORTANT QUESTION FOR LOGIC BUILDING
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails; // Set to store unique email addresses

        // Iterate through each email in the input vector
        for (string& email : emails) {
            string local, domain; // To store the local and domain parts of the email
            
            // Find the index of the '@' symbol to separate local and domain parts
            int atIndex = email.find('@');
            local = email.substr(0, atIndex); // Extract the local part (before '@')
            domain = email.substr(atIndex + 1); // Extract the domain part (after '@')

            // Process the local part to remove characters after '+' and remove '.'
            int plusIndex = local.find('+'); // Find the index of '+' in the local part
            if (plusIndex != string::npos) {
                // If '+' is found, truncate the local part to remove everything after it
                local = local.substr(0, plusIndex);
            }
            // Remove all '.' characters from the local part
            local.erase(remove(local.begin(), local.end(), '.'), local.end());

            // Combine the processed local part with the domain and insert into the set
            uniqueEmails.insert(local + "@" + domain);
        }

        // Return the number of unique emails by returning the size of the set
        return uniqueEmails.size();
    }
};

int main() {
    Solution solution;

    // Example list of email addresses
    vector<string> emails = {
        "test.email+alex@leetcode.com",
        "test.e.mail+bob.cathy@leetcode.com",
        "testemail+david@lee.tcode.com"
    };

    // Call the numUniqueEmails method and print the result
    int uniqueCount = solution.numUniqueEmails(emails);
    cout << "Number of unique email addresses: " << uniqueCount << endl;

    return 0;
}
