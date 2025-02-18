using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace ProblemAnalysis1Assignment.Models
{
    public class ProgramOfStudy
    {
        [Key]
        [StringLength(10)]
        public string Code { get; set; }  // Example: "CPA"

        [Required]
        public string Name { get; set; }   // Example: "Computer Programmer Analyst"

        public ICollection<Student> Students { get; set; }
    }
}
