# Browser-History-Manager-
The Browser History Manager is a console-based application that simulates a basic web browser's history management system. It allows users to navigate between URLs, manage their browsing history, bookmark favorite sites, and handle multiple tabs, providing a simple yet functional browsing experience.

Features:

Visit URL: Users can input a URL to "visit," which is then stored in the browsing history.
Back and Forward Navigation: Users can navigate back to previously visited URLs and forward to URLs they navigated back from, mimicking typical browser behavior.
Current URL Display: Users can see the currently active URL.
Bookmarking: Users can bookmark their current URL for easy access later.
Viewing Bookmarks: Users can view a list of their saved bookmarks.
Browsing History: Users can display their entire browsing history to revisit previously visited sites.
Multi-Tab Management: Users can create new tabs and switch between them, allowing for separate browsing sessions.

Data Structures Used:

List: A doubly linked list (std::list) is used to store the browsing history, allowing efficient insertion and deletion of URLs.
Stack: Two stacks (std::stack) are used to manage back and forward navigation, storing the URLs for easy access and manipulation.
Vector: A dynamic array (std::vector) is used to store bookmarks, allowing for flexible management of favorite sites.
Implementation Details:

The application runs in a console environment, providing a text-based interface for user interaction.
Users are presented with a menu of options and can enter their choice to perform various actions related to URL management.
The program validates user inputs and provides appropriate feedback, ensuring a smooth user experience.
