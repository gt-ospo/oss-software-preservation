# Setting up a Webserver for Caviar

Caviar has two main ways of obtaining files/software:
- a local directory specified by the `-local-dir` option
  - useful for tutorials, where files are not intended to be shared to others
- one or more webservers by the `-urls` option
  - useful for sharing VMs and related files with others

## Setting up a Webserver for Caviar

### Prerequisites:
- a domain for the webserver that points to the server's public IP address
  - Note: replace `example.com` with your domain in the examples below
  - If you are using Cloudflare, do not enable proxying (the orange cloud icon) for the domain (to keep this tutorial simple)
- a directory to store your files for Caviar
  - Note that all files will be public in this example (it is possible to set up access control, but is outside the scope of this tutorial)
  - `/storage` is used in the examples below

### Setting up a Machine for the Webserver

If you do not have a server on hand, you can rent one from a cloud provider (e.g. AWS, Microsoft Azure, Google Cloud) or VPS (virtual private server) provider (e.g. Digital Ocean, Linode, Vultr).
Make sure to choose a server with enough disk space to store the files you want to share.

You can also use a PC at home/work as a webserver, but it should have a static public IP address to itself (e.g. a home Internet connection typically does not have a static public IP address).

Some universities provide public IP addresses to staff and students as well.

For example, Georgia Tech staff and students can use their own PC as a webserver:
1. Connect a PC to LAWN via Ethernet (wired) or Wi-Fi (Ethernet is preferred as the connection it creates is more stable). 
2. Go to `portal.lawn.gatech.edu` and register your device (if necessary, i.e. your PC does not have a connection yet). 
3. [Disable the inbound firewall](https://gatech.service-now.com/technology?id=kb_article_view&sysparm_article=KB0040333) on your PC. 

### Setting up the Webserver Software

For simplicity, we will be using the [Caddy](https://caddyserver.com/) webserver software. Caddy is a modern webserver that is easy to set up and use. The following tutorial is written for Debian. However, this workflow can easily be adjusted for other operating systems (such as MacOS). 

Install Caddy: 
`sudo apt install caddy`

We will setup the webserver to serve files from a directory on the server.

Write this in the `/etc/caddy/Caddyfile` file:
```caddy
https://example.com {
  root /storage
  file_server browse # list files in the directory
}
```

Restart Caddy: `sudo systemctl restart caddy`

Make sure Caddy is running and does not have any catastrophic errors:
```bash
sudo systemctl status caddy
```
You should see a message like this:
```
$ systemctl status caddy
● caddy.service - Caddy
     Loaded: loaded (/etc/systemd/system/caddy.service; enabled; preset: ignored)
     Active: active (running) since Fri 2025-03-28 10:25:38 EDT; 1 week 5 days ago
 Invocation: c116cfd7c81f43f1bebf1cbda1ba1cc5
       Docs: https://caddyserver.com/docs/
   Main PID: 1415 (caddy)
         IP: 97.1M in, 2.5G out
         IO: 2.7G read, 44.7M written
      Tasks: 13 (limit: 9234)
     Memory: 393.5M (peak: 1.2G)
        CPU: 10min 7.220s
     CGroup: /system.slice/caddy.service
             └─1415 /usr/bin/caddy run --config /etc/caddy/Caddyfile --adapter caddyfile

Mar 28 10:24:28 server systemd[1]: Starting Caddy...
Mar 28 10:25:38 server caddy[1415]: {"level":"info","ts":1743171938.001667,"msg":"using config from f>
Mar 28 10:25:38 server caddy[1415]: {"level":"info","ts":1743171938.0291815,"msg":"adapted config to >
Mar 28 10:25:38 server systemd[1]: Started Caddy.
```

Try to connect to the server using your browser: `https://example.com`

If you see a directory listing of the files in `/storage`, then you have successfully set up a webserver.
If you see a security error or similar, Caddy may need some time to set up HTTPS certificates for your webserver.
If you cannot connect at all, the domain settings may have not been propagated yet. Try again in a few minutes.

### Uploading Files to the Webserver

You can use any method to upload files to the webserver.
One easy method is the `scp` command, which comes with the SSH suite of software.

For example, to upload a file called `43819ab8120ccef8888766cb9fe6d9e0f1ad82c97155f24331ee3d451db2c04e` to the webserver:
```bash
# make sure 43819ab8120ccef8888766cb9fe6d9e0f1ad82c97155f24331ee3d451db2c04e is in the working directory
scp 43819ab8120ccef8888766cb9fe6d9e0f1ad82c97155f24331ee3d451db2c04e example.com:/storage
```
