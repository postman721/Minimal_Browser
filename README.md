Minimal Browser is a C++ and QT5 browser.

Copyright (c) 2020 JJ Posti <techtimejourney.net>

This is free software, and you are welcome to redistribute it under GPL Version 2, June 1991″


<b>Features:</b>

- Go back. 
- Go forward.
- Stop loading.
- Print page.
- Reload page.
- Go Home (This points to current AWS hosted Postx Gnu/Linux landing page).
- Does not support http. Https only.
- Statusbar giving generic messages about page loading states.


<b>Opening links and copying links:</b>


If a link does not open automatically, right-click the link and choose the Open Link option.

If you wish to copy a specific link, right-click on it and choose Copy Link option.


Save Link and Open in New Window options from the right-click menu are not integrated yet.


<b>Navigation example, URLs should be written like this:</b>


		google.fi
		techtimejourney.net
		...
		
Do not add www. or http or https in front - things will fail.		

		
<b>Downloading files:</b>


Minimal browser does not yet support downloading files by clicking on them.

To download a file, use Copy Link option from a right-click menu. Next, open a terminal and do wget <paste_your_link_here>.


<b>Dependencies:</b> 


QT5, QWebview and its friends. Names vary upon distributions. See header file of this project for possible hints on what to install.


<b>Why make this browser?</b>


- C++ is fun to use with QT5.
- My previous Python based browsers started experiencing problems on Debian environent(certain modules missing etc.) 
- C++ hardly ever experiences trouble on Linux.
