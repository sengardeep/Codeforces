import os
import zipfile
import random
import shutil

def get_even_diff_pairs(arr):
    # Two numbers have an even difference if both are odd OR both are even.
    odds = sum(1 for x in arr if x % 2 != 0)
    evens = len(arr) - odds
    
    # Formula for pairs: n * (n - 1) // 2
    odd_pairs = (odds * (odds - 1)) // 2
    even_pairs = (evens * (evens - 1)) // 2
    
    return odd_pairs + even_pairs

def generate_testcases():
    # Make a temp folder
    os.makedirs("temp_tc", exist_ok=True)
    
    cases = []
    
    # 1. Your 5 manual test cases
    cases.append([5])
    cases.append([1, 2])
    cases.append([1, 2, 3])
    cases.append([1, 2, 3, 4, 5])
    cases.append([10, 21, 32, 43, 54, 65, 76])
    
    # 2. Add 5 new test cases
    # TC 5: All even numbers
    cases.append([2, 4, 6, 8, 10, 12, 14, 16, 18, 20])
    
    # TC 6: All odd numbers
    cases.append([1, 3, 5, 7, 9, 11, 13, 15, 17, 19])
    
    # TC 7: Medium random array
    cases.append([random.randint(1, 1000) for _ in range(100)])
    
    # TC 8: Large random array
    cases.append([random.randint(1, 10**9) for _ in range(50000)])
    
    # TC 9: Max size array (100,000 numbers)
    cases.append([random.randint(1, 10**9) for _ in range(100000)])

    # 3. Write files and zip them
    with zipfile.ZipFile("testcases.zip", "w") as zf:
        for i, arr in enumerate(cases):
            # File names
            in_name = f"in{i:02d}.txt"
            out_name = f"out{i:02d}.txt"
            
            in_path = os.path.join("temp_tc", in_name)
            out_path = os.path.join("temp_tc", out_name)
            
            # Write input file
            with open(in_path, "w") as f:
                f.write(f"{len(arr)}\n")
                f.write(" ".join(map(str, arr)) + "\n")
            
            # Write output file
            ans = get_even_diff_pairs(arr)
            with open(out_path, "w") as f:
                f.write(f"{ans}\n")
                
            # Add to zip
            zf.write(in_path, arcname=in_name)
            zf.write(out_path, arcname=out_name)

    # Clean up temp folder
    shutil.rmtree("temp_tc")
    print("Done! Check testcases.zip.")

if __name__ == "__main__":
    generate_testcases()