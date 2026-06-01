import csv
import sys

def main():
    main_dna = []
    sequence = []
    names = []
    database = {}

    i = 0

    if len(sys.argv) < 3 or len(sys.argv) > 3:
        print("Error, proper usage: databases sequences")


    with open(sys.argv[1], "r") as file:
        reader = csv.reader(file)
        header = csv.DictReader(file)
        sequence = header.fieldnames # list of headers
        num_cols = len(sequence) # number of collumns

        for row in reader:
            sub_dna = {}
            for columns in range(num_cols):
                if columns == 0:
                    continue
                else:
                    sub_dna[sequence[columns]] = row[columns]
            main_dna.append(sub_dna)
            database[row[0]] = main_dna[i]
            i = i+1

    with open(sys.argv[2], "r") as file:
        reader = csv.DictReader(file)
        dna_sequence = file.read()

    matches = []
    for m in range(len(sequence)):
        if m == 0:
            continue
        matches.append(longest_match(dna_sequence, sequence[m]))
    # TODO: Check database for matching profiles
    for name, dna in database.items():
        count = 0
        i = 0
        for key, value in dna.items():
            if matches[i] == int(dna[key]):
                count = count + 1
                i = i + 1
            else:
                i = i + 1
                break
            if count == (len(matches)):
                print(name)
                return
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
