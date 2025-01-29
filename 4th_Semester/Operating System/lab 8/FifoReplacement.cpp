#include <iostream>
#include <vector>
#include <queue>
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

    vector<int> frames(no_of_frames, -1);
    queue<int> page_queue;
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
            if (page_queue.size() == no_of_frames)
            {
                // Remove the oldest page from the frames
                int oldest_page = page_queue.front();
                page_queue.pop();
                for (int j = 0; j < no_of_frames; ++j)
                {
                    if (frames[j] == oldest_page)
                    {
                        frames[j] = ref_string[i];
                        break;
                    }
                }
            }
            else
            {
                // Find an empty frame and add the new page
                for (int j = 0; j < no_of_frames; ++j)
                {
                    if (frames[j] == -1)
                    {
                        frames[j] = ref_string[i];
                        break;
                    }
                }
            }
            // Add the new page to the queue
            page_queue.push(ref_string[i]);
            ++faults;
        }
        // Print the frames
        cout << "\n";
        for (int j = 0; j < no_of_frames; ++j)
        {
            cout << frames[j] << "\t\t";
        }

        if (!hit)
            cout << " F";
    }
    cout << "\n================================================================================\n";
    cout << "\n\nTotal Page Faults = " << faults << endl;
    return 0;
}
