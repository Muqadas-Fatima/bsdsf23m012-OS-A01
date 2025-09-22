# REPORT

## Linking rule in the Makefile
- `$(TARGET): $(OBJECTS)`build the target by linking all object files.  
- Means the final program depends on compiled `.o` files.  
- **Difference vs linking a library:**  
  - This only combines your own object files.  
  - Linking with a library adds external precompiled code (e.g., `-lm` for math library).  

## Git tags
- A tag marks a specific commit.  
- Useful: easy to identify/reproduce project states (e.g., `v1.0`).  
- **Simple tag:** just a name → pointer to a commit.  
- **Annotated tag:** includes message, date, author, and can be signed → preferred for releases.  

## GitHub Releases
- A Release = publishing a tagged version on GitHub.  
- **Purpose:** provides clear version history + release notes.  
- **Attaching binaries:** lets users download ready-to-run executables, no need to compile themselves.  
