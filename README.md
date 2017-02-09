# ECE1552

```
# CVE-2014-8176
Priority:	High
Link:		https://security-tracker.debian.org/tracker/CVE-2014-8176
Description:	
The dtls1_clear_queues function in ssl/d1_lib.c in OpenSSL before
0.9.8za, 1.0.0 before 1.0.0m, and 1.0.1 before 1.0.1h frees data 
structures without considering that application data can arrive 
between a ChangeCipherSpec message and a Finished message, 
which allows remote DTLS peers to cause a denial of service (memory corruption 
and application crash) or possibly have unspecified other impact via
unexpected application data.
```
