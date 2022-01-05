*******************************
Chapter 1. Project Management
*******************************

.. include:: /global.rst


Topics:

- motivation and background
- MOST IMPORTANT: computer environment. Files to download and software to install before the lecture. e.g., put environment initializer here :download:`env.sh <src/git/env.sh>`.
- Work modes - local, server, collaboration.


Sections
===========

.. toctree::
    :maxdepth: 2
 
    git
    document
    work-on-servers


Lecture Slides & Resources 
===========================

.. table::
    :class: tight-table

    =========================================== =================================================================
    Section                                     Slides
    =========================================== =================================================================
    Document Your Project                       :download:`PPT <src/document/Ch1.2-document.pptx>`
    Work on the Server Machines                 :download:`PPT <src/work-on-servers/Ch1.3-work-on-servers.pptx>`
    =========================================== =================================================================


Prerequisites
===============

The following softwares are required in this Chapter 

- An Internet browser (e.g., Chrome, Firefox).
- A Python environment. Make sure that a python interpreter (``>=3.5``) is installed.
- Python package ``sphinx`` and ``sphinx-rtd-theme``. Follow the section :ref:`project-man-doc-sphinx-start`
  to install them, so that the command ``sphinx-quickstart`` works.
- Shell commands, ``ssh``, ``scp``, ``rsync``, ``sshfs`` and ``wget``. Install them 
  using the package manager of your local system, e.g., ``apt-get`` in a Ubuntu distribution.