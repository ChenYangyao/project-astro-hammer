*******************************
Document Your Project
*******************************

.. include:: /global.rst

What is a Documentation ?
============================

A documentation is the major part of a published project that tells uses about how to use the functionality 
your project provided. In scientific community, the importance of documentation is usually underestimated,
partly because the hurry of science people and the lack of target users. But this is not the reason for skipping
this vital part - a clear documentation is the first step to increase the popularity of your project.

.. _project-man-doc-parts:

A documentation usually consists of the following parts.

- A **brief introduction** to the project. Its name, logo, motivation, target users, main features, advantages over 
  other competitors. As a reliable developer, it is also necessary to hint the drawbacks/caveats of your project.
- A **quick start guide**, including how to download the resources, install the software, setup the run-time environment,
  how to quickly begin a "hello world" example, and where to go for the next step.
- A **tutorial** which introduce the main components of your project. Step by step guides should be provided to users.
- A **detailed reference**. List every detail of the project that you want to provide to the users. For a library, list 
  every (sub-)modules, classes, function and variables, and carefully describe them.
- Other project-related information. The license, the list of contributors, how to seek for help, how to raise issues.

Many good examples of documentations are written by various developers. We explore some of them in the following.

**Nlohmann JSON**

.. margin::
    
    .. tip::

        JavaScript Object Notation (`JSON <https://www.json.org/json-en.html>`_) is de facto standard data 
        representation format in Web development due to the popularity of JavaScript programming language.
        It represents dictionaries, arrays, strings and number by serialized string. It is human readable
        and therefore machine-independent.


`Nlohmann JSON <https://github.com/nlohmann/json>`_ is a modern C++ library for 
parsing/dumping JSON data streams. It is particularly
useful for loading configure files at the entrance of a program. We will give a more 
complete introduction to the JSON libraries
in the :doc:`Python Programming <../python-programming/index>` and :doc:`C++ programming <../cpp-programming/index>`
chapters. We will also introduce the JavaScript programming in the :doc:`GUI Development <../gui-development/index>` 
chapter.
But let us focus on its documentation organization in this section.

Nlohmann JSON library is hosted on Github, and provides its documentation in a single **Markdown** page, suitable
for such a single-usage library. The main components of the documentation are:

- The **design goals**, i.e., the brief introduction.
- The **integration**, i.e., how to install the library.
- The **examples**, i.e., quick start and tutorials.
- The **full API** details are provided in another website.
- Other related information.


Therefore, it is fully compliant to the :ref:`required parts <project-man-doc-parts>` we have introduced.


**NumPy**

`NumPy <https://numpy.org/doc/stable/>`_ is the fundamental package for scientific computation in Python.
It provides basic array/matrix operations, linear algebras, statistical operations and random number generators, etc.
NumPy will be introduced in the :doc:`Python Programming/Scientific Computation <../python-programming/index>` 
section, here we focus on its documentation organization.

NumPy is a large library, so its documentation should be hosted on a `separate website <https://numpy.org/doc/stable>`_.
It has several versions, from old, stable to those for developers. Each of those version has a separate entrance 
of documentation, but they all share the same structure:

- **Why is NumPy** states the its design goal and target users.
- **Absolute beginner's guide** tells the installation and the most simple usage. Install and Quick start are 
  organized in distinct part because its wide target.
- **Tutorials** and **How tos** and **fundamentals** introduce its main components.
- The **API reference** is so long, so it is provided through a separate page. NumPy is written in C so its full 
  C-API is also provided.

Despite of complex of NumPy, its documentation still follows the common structures with 
all :ref:`required parts <project-man-doc-parts>`.


**The IllustrisTNG Project**

`IllustrisTNG <https://www.tng-project.org/>`_ ...

Overview of of Documentation-Writting Tools
=============================================

Documentation can be written by any human-readable text format. The most common formats are

- **Txt**: plain text format, usually with file name suffix :rawtext:`.txt`. It is supported on almost any 
  operating system and almost any text editor. Some raw catalogs in astronomy provide 
  documentation with txt format, mainly due to the historical reason, simplicity 
  requirement and stability requirement.
  Examples include the `galaxy group catalogs <https://gax.sjtu.edu.cn/data/Group.html>`_ of Yang X.-H. et al.
- **Markdown**: a simple, linear-layout markup language, usually with suffix :rawtext:`.md`. 
  Markdown is designed as a simplified version of **HTML**
  language - only the most important features, like heading, paragraph, hyperlink, image, list, table, etc., are 
  preserved. `Github <https://github.com/>`_ uses it as the default (and only available) documentation format.
- **Sphinx** and **ReStructuredText (ReST)**: a full featured documentation format, 
  usually with suffix :rawtext:`.rest` or :rawtext:`.rst`,
  particularly suitable for writting
  documentation for codes. It is a super-set of **Markdown**, and a subset of **HTML**. 
  This project, `AstroHammmer <https://project-astro-hammer.readthedocs.io/>`_,
  is written in **ReST** and organized by **Sphinx**.
- **HyperText Markup (HTML)**: a full featured language, capable for any documentation. 
  A HTML file is usually suffixed with :rawtext:`.html`.
  It is a dragon-killing 
  technique, very complicated, but able to control every aspect (every character or even every pixel) of 
  your documentation. Every modern website uses **HTML** pages to describe its structure.

Plain text is so simple that we cannot tell much about it in AstroHammmer. **HTML** is overcomplicated so that 
half of a individual chapter, :doc:`GUI Development <../gui-development/index>`, is provided to introduce it.
In the following of this section, we introduce how to use **Markdown** and **ReST**/**Sphinx**.

Some programming languages provide library tools to generate documentations from inline comments of source files.
This indeed helps to generate the API reference, but helps little for other parts of a full documentation, i.e., 
the basic techniques in this section are still mandatory for documentation.
We will explore the language-specific documentation tools in the corresponding chapters.

Topics:

- Markdown
- Latex (optional)
- Sphinx
- HTML (optional)
- Automated tools for generating docs (introduced in programming language sections).