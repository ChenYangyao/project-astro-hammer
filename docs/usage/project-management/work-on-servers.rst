*******************************
Work on the Server Machines
*******************************

.. include:: /global.rst

About Servers
======================

Massive tasks are usually executed in specially designed machines, called "server machine".
Those machines are usually visited in remote, and shared by many users. 
To serve all the users, and let any of them feel like they own the machine (i.e., do not 
feel the existence of other users), the machine starts a program (or more precisely, a process)
for each of its user. Such program is called a "server" - i.e., a server is a software 
running on the machine, but it is not the machine itself.

There are a number of servers that we frequently used:

- The shell: the surface above the operating system kernel. It provides abstract
  functionality to the user, hide details about how the operating system works.
- The kernel of the operating system: the core functionality set of the system.
  Typically examples are "Linux", "Darwin", and "WindowsNT". Ordinary users 
  do not touch the kernel directly. They use those functionality by the shell
  or by the GUI of the system.
  Application programmers, use the "system calls", i.e., a set of functions provided 
  in the programming languages, to interact with the kernel.
  System developers directly modify the kernel, by either writing kernel modules 
  or changing existing codes of the kernel.
- The HTTP server: serves a website. For example, when you visit `https://lig.astro.tsinghua.edu.cn/ <https://lig.astro.tsinghua.edu.cn/>`_,
  the server of LIG returns a page, a set of style files and script files, to your browser. 
  The browser renders them to the web page you see.

This talk introduces a set of specific functionality provided by the "shell" that 
are relevant to your daily access to the server machine remotely. A more complete 
guide on the shell itself will be presented in the section :doc:`../development-environment/shell`.


ssh - Linking to the Server
=============================

To start a shell remotely, run :rawtext:`ssh` command in you local computer:

.. code-block:: bash

    $ ssh [-p Port] RemoteAddress

Examples:

.. code-block:: bash

    $ ssh 166.111.131.54
    $ ssh hubble@166.111.131.54
    $ ssh -p 2333 hubble@166.111.131.54

The first use an IP(v4) address as the RemoteAddress. If the server machine 
is not public, ssh will ask your user name and password.
The second specify an user name. The third specify a Port number, which 
is defined by the ssh host in the server machine, and you must 
ask the system administrator for its detail. By default, the Port number 
is "22".

.. _project-man-work-on-servers-ssh-no-password:

Using ssh Without a Password
------------------------------
Type the password everytime is boring. But to ensure the safety, it is a 
necessary step. The solution is to let the local SSH command automatically 
provide information to the remote for authentication.

First, enter the directory :rawtext:`~/.ssh/` to see whether there is 
two files named :rawtext:`id_rsa.pub` and :rawtext:`id_rsa`. If not, 
generate them by:

.. code-block:: bash

    $ ssh-keygen -t rsa [-C YourEmail]

For example:

.. code-block:: bash

    $ ssh-keygen -t rsa -C 'hubble@cis.edu'

The email is optional.

The file :rawtext:`id_rsa.pub` is a public key that tells people or the server 
machine who you are. You may give it to other people. the file :rawtext:`id_rsa`
is a private key that verifies you are the person named by the public key. 
Please always keep the private key secret.

Now, upload the public key to the remote machine, simply by running:

.. code-block:: bash

    $ ssh-copy-id [-p Port] -i ~/.ssh/id_rsa.pub RemoteAddress

For example:

.. code-block:: bash

    $ ssh-copy-id -p 2333 -i ~/.ssh/id_rsa.pub hubble@166.111.131.54

Now, you can use SSH to login into the remote machine without a password. 
Other commands that use SSH as data transfering protocol also do not need a 
password.

Note that some machines may turn off the auto-authentication. In those machines, 
a password is necessary.

Access to Remote Files
===============================================

scp - Copying File From/To the Remote
------------------------------------------

To move files between two machines, simply run the :rawtext:`scp` (copy-with-ssh) 
command:

.. code-block:: bash

    $ scp [-P Port] [-r] SourceAddress DestAddress

Where the "SourceAddress" and "DestAddress" can be a local or a remote file or 
directory. If "SourceAddress" is a directory, like :rawtext:`foo` or :rawtext:`foo/`,
you must use :rawtext:`-r` to recursively copy its files and sub-directories.

For example, the local files in the current directory are:

.. code-block:: text

    foo/
      |- bar.txt
      |- baz.py

You may copy them to a server machine by 

.. code-block:: bash

    $ scp -r foo hubble@166.111.131.54:/home/hubble

The directory :rawtext:`foo` and its contents are copied to under the remote
:rawtext:`/home/hubble` directory.

Sometimes a large copy requires a long time to finish. In such case, simply run :rawtext:`scp`
in the background:

.. code-block:: bash

    $ scp -r foo hubble@166.111.131.54:/home/hubble

    # Enter the password if asked.
    # Then press Ctrl+Z to stop scp and release the shell prompt.

    $ bg

The command :rawtext:`bg` puts the task in the background so that you can 
you the shell for other tasks.

Note that :rawtext:`scp` always copies all contents, no matter whether the "DestAddress" already 
has them or not. The following command, :rawtext:`rsync`, on the other hand, compares
local and remote files, and copies only if necessary.


rsync - Synchronizing With Remote File System
-----------------------------------------------

:rawtext:`rsync` is a more convenient command for transfering big data or large amounts 
of files. It is also a good method to make local back-up for local files. To use :rawtext:`rsync`, 
run:

.. code-block:: bash

    $ rsync [Option]... SourceAddress DestAddress    

Take the above local directory :rawtext:`foo/` as an example, to synchronize it 
to a server machine, run:

.. code-block:: bash
    
    $ rsync -azP foo hubble@166.111.131.54:/home/hubble

The options are:

- :rawtext:`-a`: a combination of a set of options, means make "archive". This 
  enables recursive transfering for directory, preserve symbolic links, modification
  times, and user permission masks. This is usually a good choice.
- :rawtext:`-z`: compress the data before transfering them. This is usually also 
  a good choice, because it reduces the amounts of data to transfer.
- :rawtext:`-P`: the combination of :rawtext:`-progress` and :rawtext:`partial`.
  The first means a progress bar is shown, which allows visual inspection of the progress.
  The second means a local or remote temporary record is made before finishing 
  the transfering. If the task is interupted for some reason, the later invode of 
  :rawtext:`rsync` will resume the un-finished job. This is a good choice 
  to transfer big data files.

Without any modification, the second time you run :rawtext:`rsync` for the same 
directory, no transfering will be made because :rawtext:`rsync` only synchronizes
those changed files.

Note that the directory argument :rawtext:`foo` is different from :rawtext:`foo/`.
The previous puts the directory :rawtext:`foo` as well as its contents to the 
remote folder :rawtext:`/home/hubble`, while the later moves only its contents.

If a port number is required, you may pass an additional option, like
:rawtext:`$ rsync -azP -e 'ssh -p Port' ...`.

In some cases, you want just to synchronize a part of the directory, and ignore 
some of the files. In such case, use option :rawtext:`--exclude='Pattern'` or :rawtext:`--exclude={'Pattern1','Pattern2', ...}`
to exclude them. For example:

.. code-block:: bash 

    $ rsync -azP --exclude={'bar.txt','baz.py'} foo hubble@166.111.131.54:/home/hubble

If lots of files need to be excluded, just create a new file, e.g., called :rawtext:`rsync-excl.txt`, 
write down all the patterns into it, one per line, and specify the exclusion as 
:rawtext:`--exclude-from=rsync-excl.txt`.

:rawtext:`rsync` allows double-check of the contents before real synchronization:

.. code-block:: bash

    $ rsync -azP -nv foo hubble@166.111.131.54:/home/hubble

Here the additional options are 

- :rawtext:`-n`: dry-run. With this option, :rawtext:`rsync` prints the files
  to be transferred, but does not really do it.
- :rawtext:`-v`: verbose, which allow detailed information to print.

With both :rawtext:`-n` and :rawtext:`-v` options, you can check the output:

.. code-block:: text

    sending incremental file list
    foo/
    foo/bar.txt
    foo/baz.py

    sent 122 bytes  received 55 bytes  354.00 bytes/sec
    total size is 0  speedup is 0.00 (DRY RUN)

If correct, you may drop the :rawtext:`-nv` and make actual synchronization.


sshfs - Mounting Remote File System to Local 
-----------------------------------------------

If you want to visit the remote files like that they are in the local file 
system, but you do not want any copy, :rawtext:`sshfs` can help. This commands
simply "mounts" a remote directory into the local file system, so that 
it appears in the local file tree:

.. code-block:: bash
    
    $ mkdir tempdir
    $ sudo sshfs -o allow_other,IdentityFile=/home/edwin/.ssh/id_rsa hubble@166.111.131.54:/home/hubble ./tempdir

The first command creates a local directory as the mounting point. It must be empty or otherwise :rawtext:`sshfs`
rejects the mounting.
The second command needs super-user privilege, which can be authorized by :rawtext:`sudo`. 
Through :rawtext:`-o` you can pass one or more comma-separated options. Here :rawtext:`allow_other`
means that you can use remote files owned by other users. :rawtext:`IdentityFile` points 
to the authentication file we created in :ref:`project-man-work-on-servers-ssh-no-password`.
If omitted, you will be asked for a password later.
The finally two positional arguments are just like :rawtext:`scp`, the source directory and the mounting point.

After the mounting, you can use remote files just like they are in the local system. You may edit them,
and the changes are reflected to the remote. But depending on the network performance, it might be slow.

To un-mount the remote file system, run:

.. code-block:: bash

    $ sudo umount ./tempdir

git - Synchronize your Code Repository
----------------------------------------

Codes of human-readable text files are usually organized as :rawtext:`git` repositories. 
Git also provides functionality to synchronize those repositories between computers. 

Suppose that you have a local git repository created by the way described 
in the section :doc:`./git`. 
To synchronize it to a remote machine, create an "empty" git repository on 
your desired location in the remote machine. For example:

.. code-block:: bash

    mkdir repo-name && cd repo-name
    git init

To enable a push to this repository, run the following configuration commands 
in this repository:

.. code-block:: bash

    git config receive.denyCurrentBranch ignore
    git config --bool receive.denyNonFastForward false

In your local repository, bind the remote repository by:

.. code-block:: bash

    git remote add origin hubble@166.111.131.54:/home/hubble/repo-name/.git

Here, ``origin`` may be other arbitrary name for the remote repository. 
Then, any local change can be synchronized to remote by ``push``:

.. code-block:: bash

    git push origin master

In the remote repository, run ``reset`` to see the changes:

.. code-block:: bash

    git reset --hard

.. hint::

    The above git configurations and reset operations are dangerous when the 
    modifications are made both remotely and locally. Refer to their manuals 
    for detail.

wget - Download File From HTTP Server
---------------------------------------

The above commands are all ssh-based. They work fine for a private remote machine, i.e., 
you must have a password to fetch the data from it.

Some resources, on the other hand, are made public available by HTTP servers. Commercial
sites, like GoogLe, Amazon, Taobao, all fit into this category.
To get those resources, the simplest way is to use your browser, like Chrome, Firefox, 
and Edge. But some resources are distributed at many different locations, therefore
requiring automated script to download them. :rawtext:`wget` is provided for this purpose.

The simplest usage for :rawtext:`wget` is to download a webpage, like HTML document. 
For example, to download the index page of LIG - an astrophysics team in China, 
run:

.. code-block:: bash

    $ wget https://lig.astro.tsinghua.edu.cn/

This is equivalent to ask the LIG server "hey, give me the index document under the 
path https://lig.astro.tsinghua.edu.cn/". The HTTP server responses to your 
query, and returns to :rawtext:`wget` what you asked - a :rawtext:`index.html`
file.

To download any specific resource from a HTTP server, run:

.. code-block:: bash

    $ wget [Option]... URL...

Here :rawtext:`URL` means Unified Resource Locator, which we usually called 
web address.

:rawtext:`wget` also allows recursive downloading, i.e., downloads all 
files under a page, with user-specified criteria. For more detailed 
usage, see its manual page by running :rawtext:`$ man wget`.

