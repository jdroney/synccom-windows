# Connect

Opening a handle using this API will only give you access to the synchronous functionality of the card.

###### Support
| Code | Version |
| ---- | ------- |
| synccom-windows | 1.0.0 |


## Connect
The Windows [`CreateFile`](http://msdn.microsoft.com/en-us/library/windows/desktop/aa363858.aspx) is used to connect to the port.

| System Error | Value | Cause |
| ------------ | -----:| ----- |
| `ERROR_FILE_NOT_FOUND` | 2 (0x02) | Port not found |
| `ERROR_ACCESS_DENIED` | 5 (0x02) | Insufficient permissions |

###### Examples
Connect to port 0.
```c
#include <Windows.h>
...

HANDLE h;

h = CreateFile("\\\\.\\SYNCCOM0", GENERIC_READ | GENERIC_WRITE, 0, NULL,
               OPEN_EXISTING, 0, NULL);
```


### Additional Resources
- Complete example: [`examples/tutorial.c`](https://github.com/commtech/synccom-windows/blob/master/examples/tutorial/tutorial.c)