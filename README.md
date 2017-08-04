# TodoList
Performs to have tasks with different priorities and move to another container according to their priorities

*** HOW TO BUILD THE PROJECT ON WINDOWS ***

1. Install Microsoft Visual Studio 2013 Professional/Premium/Ultimate.

2. Install Visual Studio Add-in 1.2.4 for Qt5:
   http://download.qt.io/official_releases/vsaddin/qt-vs-addin-1.2.4-opensource.exe

3. Open the solution TodoList.sln.

4. Click on QT5 item in the main menu. Choose Qt Options item. Switch to Qt Versions tab in the opened window.
   Press Add button. Enter 'Qt 5.5.1' in the Version name edit box (without quotes). Specify full path to Dependencies\Qt folder in the Path edit box.
   Press OK button to exit Add New Qt Version window and OK again to exit Qt Options window.

5. Build the solution in Debug or Release configuration as usual. Copy of required dependencies is done
   automatically via Visual Studio post-build commands.
