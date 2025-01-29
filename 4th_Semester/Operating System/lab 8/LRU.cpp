#include <iostream>
#include <vector>
using namespace std;
int main()
{
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
    for (int i = 0; i < no_of_pages; ++i)
    {
        cin >> ref_string[i];
    }
    vector<int> frames(no_of_frames, -1); // -1 indicates an empty frame
    vector<int> last_used(1000, -1);      // Track the last used index of pages (assume max page number is 1000)
    int faults = 0;
    cout << "\n================================================================================\n";
    for (int i = 0; i < no_of_frames; ++i)
        cout << "frame[" << i << "]\t";
    cout << "page fault";
    cout << "\n================================================================================\n";
    for (int i = 0; i < no_of_pages; ++i)
    {
        bool hit = false;
        // Check if the page is already in the frames
        for (int j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == ref_string[i])
            {
                hit = true;
                break;
            }
        }
        if (!hit)
        {
            // If there is an empty frame, put the page in that frame
            bool empty_frame = false;
            for (int j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                { // Empty frame found
                    frames[j] = ref_string[i];
                    empty_frame = true;
                    break;
                }
            }
            // If no empty frame, replace the least recently used page
            if (!empty_frame)
            {
                int lru_index = -1, min_last_used = i;
                for (int j = 0; j < no_of_frames; ++j)
                {
                    if (last_used[frames[j]] < min_last_used)
                    {
                        min_last_used = last_used[frames[j]];
                        lru_index = j;
                    }
                }
                frames[lru_index] = ref_string[i]; // Replace the least recently used page
            }
            ++faults; // Increment page fault count
        }
        // Update the last used time for the current page
        last_used[ref_string[i]] = i;
        // Print the current frame status
        cout << "\n";
        for (int j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == -1)
                cout << "-\t\t"; // Empty frame
            else
                cout << frames[j] << "\t\t";
        }
        if (!hit)
            cout << " F"; // Indicate a page fault occurred
    }
    cout << "\n================================================================================\n";
    cout << "\n\nTotal Page Faults = " << faults << endl;
    return 0;
}
