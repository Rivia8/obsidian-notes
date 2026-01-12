18-05-2025 20:16

Tags: [[Operating Systems]]

# Daemon Processes

A **daemon process** is a background process that runs independently of interactive user sessions. They usually start at system boot and keeps running in the background to provide some kind of service.

**Key Characteristics:**

| Characteristic              | Description                                                                |
| --------------------------- | -------------------------------------------------------------------------- |
| **Background execution**    | Daemons are not tied to a terminal. You don’t see them directly.           |
| **Long-lived**              | They usually run continuously for a long time (until shutdown or failure). |
| **No controlling terminal** | Detached from user input/output; does not interact with users.             |
| **Often started at boot**   | Many daemons start when the OS boots up.                                   |
| **End with “d” (usually)**  | Their names often end in “d” (e.g., `sshd`, `httpd`, `systemd`).           |

They wait in the background for something to happen and so it makes them ideal for services for printers and servers.
They prevent **clutter** in the **terminal**.