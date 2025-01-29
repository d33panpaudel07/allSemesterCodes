#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int no_of_frames, no_of_pages;
    // Read number of frames
    cout << "Enter number of frames: ";
    cin >> no_of_frames;
    // Read number of pages
    cout << "Enter number of pages: ";
    cin >> no_of_pages;
    vector<int> ref_string(no_of_pages);
    // Read page reference string
    cout << "Enter page reference string: ";
    for (int i = 0; i < no_of_pages; ++i) {
        cin >> ref_string[i];
    }
    vector<int> frames(no_of_frames, -1);  // Initialize frames with -1 to indicate empty
    int faults = 0;
    cout<<"\n================================================================================\n";
    for (int i = 0; i < no_of_frames; ++i)
        cout << "frame[" << i << "]\t";
    cout << "page fault";
    cout<<"\n================================================================================\n";
    for (int i = 0; i < no_of_pages; ++i) {
        bool hit = false;
        // Check if the page is already in the frames (hit)
        for (int j = 0; j < no_of_frames; ++j) {
            if (frames[j] == ref_string[i]) {
                hit = true;
                break;
            }
}
        if (!hit) {
            // Page fault occurs
            // Check if there's any empty frame
            bool inserted = false;
            for (int j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    frames[j] = ref_string[i];  // Insert the page in the empty frame
                    ++faults;
                    inserted = true;
                    break;
                }
            }
            // If no empty frame is found, apply optimal replacement
            if (!inserted) {
                // Determine which page to replace (optimal page replacement strategy)
                int replace_index = -1;
                int farthest = -1;
                for (int j = 0; j < no_of_frames; ++j) {
                    int future_index = -1;
                    // Search for the next occurrence of the page in the future
                    for (int k = i + 1; k < no_of_pages; ++k) {
                        if (frames[j] == ref_string[k]) {
                            future_index = k;
                            break;
                        }
                    }
                    // If the page is never used again, replace it
                    if (future_index == -1) {
                        replace_index = j;
                        break;
                    }
                    // Track the page that is used farthest in the future
                    if (future_index > farthest) {
                        farthest = future_index;
                        replace_index = j;
                    }
                }
                // Replace the page in the frames
                frames[replace_index] = ref_string[i];
                ++faults;
            }
        }
        // Print the frames
        cout << "\n";
        for (int j = 0; j < no_of_frames; ++j) {
            cout << frames[j] << "\t\t";
        }
        if (!hit)
            cout << " F";  // Mark page fault
    }
    cout << "\n================================================================================\n";
    cout << "\n\nTotal Page Faults = " << faults << endl;
    return 0;
}
