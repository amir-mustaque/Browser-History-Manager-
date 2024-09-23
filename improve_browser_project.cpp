#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <vector>
#include <algorithm> // Include this for std::find

using namespace std;

class BrowserHistory {
private:
    list<string> historyList;
    list<string>::iterator current; // Current URL pointer

    stack<string> backStack, forwardStack;
    vector<string> bookmarks;

public:
    BrowserHistory() {
        current = historyList.end();
    }

    void visitURL(const string& url) {
        if (current != historyList.end()) {
            forwardStack = stack<string>(); // Clear forward history
        }
        historyList.push_back(url);
        current = --historyList.end();
        backStack.push(url);
        cout << "Visited: " << url << endl;
    }

    void goBack() {
        if (backStack.size() <= 1) {
            cout << "No previous URL." << endl;
            return;
        }
        forwardStack.push(backStack.top()); // Push the current URL to forward stack
        backStack.pop();
        // Find the previous URL in the history list and update the 'current' iterator
        current = find(historyList.begin(), historyList.end(), backStack.top());
        cout << "Going back to: " << backStack.top() << endl;
    }

    void goForward() {
        if (forwardStack.empty()) {
            cout << "No forward URL." << endl;
            return;
        }
        backStack.push(forwardStack.top()); // Push forward URL to the back stack
        // Find the next URL in the history list and update the 'current' iterator
        current = find(historyList.begin(), historyList.end(), forwardStack.top());
        forwardStack.pop();
        cout << "Going forward to: " << *current << endl;
    }

    void showCurrentURL() {
        if (current != historyList.end()) {
            cout << "Current URL: " << *current << endl;
        } else {
            cout << "No URL visited yet." << endl;
        }
    }

    void addBookmark() {
        if (current != historyList.end()) {
            bookmarks.push_back(*current);
            cout << "Bookmarked: " << *current << endl;
        } else {
            cout << "No URL to bookmark." << endl;
        }
    }

    void showBookmarks() {
        if (bookmarks.empty()) {
            cout << "No bookmarks added yet." << endl;
            return;
        }
        cout << "Bookmarks:" << endl;
        for (const string& url : bookmarks) {
            cout << "- " << url << endl;
        }
    }

    void showHistory() {
        if (historyList.empty()) {
            cout << "No history available." << endl;
            return;
        }
        cout << "History List:" << endl;
        for (const auto& url : historyList) {
            cout << "- " << url << endl;
        }
    }
};

// Multi-Tab Management
class Browser {
private:
    unordered_map<int, BrowserHistory> tabs;
    int activeTab;

public:
    Browser() {
        activeTab = 1;
        tabs[activeTab] = BrowserHistory();
    }

    void newTab() {
        int newTabID = tabs.size() + 1;
        tabs[newTabID] = BrowserHistory();
        activeTab = newTabID;
        cout << "New tab created. Active tab is now: Tab " << activeTab << endl;
    }

    void switchTab(int tabID) {
        if (tabs.find(tabID) != tabs.end()) {
            activeTab = tabID;
            cout << "Switched to Tab " << activeTab << endl;
        } else {
            cout << "Tab " << tabID << " does not exist." << endl;
        }
    }

    void visitURL(const string& url) {
        tabs[activeTab].visitURL(url);
    }

    void goBack() {
        tabs[activeTab].goBack();
    }

    void goForward() {
        tabs[activeTab].goForward();
    }

    void showCurrentURL() {
        tabs[activeTab].showCurrentURL();
    }

    void addBookmark() {
        tabs[activeTab].addBookmark();
    }

    void showBookmarks() {
        tabs[activeTab].showBookmarks();
    }

    void showHistory() {
        tabs[activeTab].showHistory();
    }
};

// Main Menu
void menu() {
    Browser browser;
    int choice, tabChoice;
    string url;

    while (true) {
        cout << "\n1. Visit URL\n2. Back\n3. Forward\n4. Show Current URL\n5. Bookmark Current Page\n6. Show Bookmarks\n7. Show History\n8. New Tab\n9. Switch Tab\n10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter URL: ";
                cin >> url;
                browser.visitURL(url);
                break;
            case 2:
                browser.goBack();
                break;
            case 3:
                browser.goForward();
                break;
            case 4:
                browser.showCurrentURL();
                break;
            case 5:
                browser.addBookmark();
                break;
            case 6:
                browser.showBookmarks();
                break;
            case 7:
                browser.showHistory();
                break;
            case 8:
                browser.newTab();
                break;
            case 9:
                cout << "Enter Tab ID to switch: ";
                cin >> tabChoice;
                browser.switchTab(tabChoice);
                break;
            case 10:
                cout << "Exiting browser..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}
