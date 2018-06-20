# shakespeare-quote
Displays a random Shakespeare quote. Inspired by the common Unix command-line program, "fortune".

For more information, view the project on my website here: http://peppergeist.com/pages/shakespeare-quote.html



Currently running version 0.9 as not all quote files have been fully populated.

## Installation

To build: run `make`. This will compile the program, create a bin/ directory in the repository, and place the binary there.

To install to path: run `make install`. This will compile the program and place it in `/usr/local/bin` and place the data files in `/usr/local/opt/shakespeare-quote`.

To uninstall from path: run `make uninstall`. This will remove the binary and data files from your path if they exist.


## Usage

Type `shakespeare-quote` in the terminal after installation to generate a random quote from one of the bard's works. You can provide additional options as well to influence the output or run it in debug mode. Available options:

* `shakespeare-quote [-g | --group filename]`: Specify a particular group of works to pick from. Groups available by default are listed below.
  * _all_: Pick from all works.
  * _comedy_: Pick from all comedies.
  * _english-history_: Pick from all English history plays, specifically.
  * _history_: Pick from all histories.
  * _play_: Pick from all plays.
  * _problem-play_: Pick from one of the three Roman history plays -- Antony and Cleopatra, Coriolanus, and Julius Caesar.
  * _romance_: Pick from all romances.
  * _sonnet_: Pick a random sonnet.
  * _tragedy_: Pick from all tragedies.
* `shakespeare-quote [-w | --work filename]`: Specify a particular work to pick a quote from. Overrides `--group` if both are provided.
* `shakespeare-quote [-d | --debug]`: Run the program in debug mode. This provides additional information in error reporting and displays the random numbers which influence file choice.
* `shakespeare-quote [-v | --version]`: Print the version of the program prior to printing a quote.