# **CS 300 Project One – Portfolio Reflection**

## **Reflection**

### **What was the problem you were solving in the projects for this course?**
The objective of the project was to develop a program to support academic advisors by organizing and displaying course information. Specifically, the program needed to load course data from a file, display a list of all computer science courses in alphanumeric order, and provide detailed information and prerequisites for a specific course upon request.

### **How did you approach the problem?**
I began by analyzing the requirements and identifying which data structures (vector, hash table, and binary search tree) could best address each task. I broke the problem into modular components, such as file reading, course object creation, and data organization, then implemented pseudocode for each structure. Understanding data structures was essential, as their properties (for example: search speed, ordering, memory use) directly impacted both performance and maintainability.

### **How did you overcome any roadblocks you encountered while going through the activities or project?**
One of the main challenges I faced was designing pseudocode that could efficiently sort and retrieve course data depending on the structure used. I revisited Big O complexity principles to evaluate runtime behavior, which helped clarify the trade-offs between data structure choices. I also iterated on feedback from earlier milestones to refine my approach, ensuring a more robust final submission.

### **How has your work on this project expanded your approach to designing software and developing programs?**
This project reinforced the importance of selecting the right data structure during the planning phase. It also taught me to design for flexibility by separating concerns (file handling, object modeling, and display logic). By building a reusable structure in pseudocode before coding, I developed a stronger architectural mindset that will benefit future development work.

### **How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?**
I have learned to emphasize clarity and modularity in both pseudocode and real code. Using meaningful naming conventions, limiting nested logic, and structuring the program into logical sections has made it easier to test, update, and reuse. As a result, I now approach every program with the intent to make it easy to read and extend, not just to make it work.

---

## **Interpreting User Needs and Using User Stories**

- **Start with problems, not features:** Identify who the user is, what they are trying to do, why it matters, and what success looks like. Capture pain points, constraints, and measurable outcomes.
- **Turn needs into user stories:**
  - *As a \[role\], I want \[capability\], so that \[outcome\].*
  - This keeps every feature tied to user value.
- **Add acceptance criteria:** Use Given–When–Then scenarios to create a shared definition of done.
- **Validate early:** Build quick prototypes or wireframes, then refine stories based on feedback and data.

**Example for the Course Advisor program:**
- **Story:** *As an academic advisor, I want to search for a course by ID and see its prerequisites, so that I can guide students on the correct course sequence.*
- **Acceptance Criteria:**
  - Given a course catalog file is loaded, when I enter a valid course ID, then the program shows the course name, ID, and its prerequisites.
  - Given the course has no prerequisites, when I request details, then the program explicitly shows that there are none.
  - Given I enter an invalid course ID, when I search, then the program displays a clear error message and suggests valid next steps.

---

## **How I Develop Programs and Agile Practices I Will Use**

- **Work in vertical slices:** Deliver small, end-to-end increments that a user can try.
- **Short feedback loops:** Two-week sprints, a demo every sprint, and usability checks on representative data.
- **Technical habits:**
  - Trunk-based development with feature flags
  - Continuous integration with automated builds and tests on every commit
  - Test pyramid: unit first, then integration, then UI
  - Keep architecture simple and use spikes to explore risky areas
- **Agile processes to incorporate:**
  - Product backlog with story mapping and clear priorities
  - Definitions of Ready and Done to protect quality
  - Sprint Planning, Daily Scrum, Sprint Review, and Retrospective
  - Weekly backlog refinement to split work, add acceptance criteria, and size with story points
  - Lightweight metrics: lead time, throughput, work in progress, escaped defects

---

## **What It Means to Be a Good Team Member in Software Development**

- **Communicate early and clearly:** Surface risks, ask for help, and keep stakeholders informed.
- **Own outcomes, not just tasks:** Focus on user value, reliability, and maintainability.
- **Be reliable and respectful:** Meet agreements, give and receive code review feedback constructively, and document decisions.
- **Swarm on blockers:** Help teammates finish work to keep flow moving rather than starting more work in progress.
- **Raise the bar:** Write clean code, add tests, improve observability, and leave the codebase better than you found it.
- **Be inclusive and growth oriented:** Mentor, pair when useful, and invite diverse perspectives so the team learns faster.
