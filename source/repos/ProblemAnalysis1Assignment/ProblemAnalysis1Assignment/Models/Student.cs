using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using Microsoft.AspNetCore.Mvc.ModelBinding.Validation;

namespace ProblemAnalysis1Assignment.Models
{
    public class Student
    {
        [Key]
        public int Id { get; set; }

        [Required]
        [StringLength(50)]
        public string FirstName { get; set; }

        [Required]
        [StringLength(50)]
        public string LastName { get; set; }

        [Required]
        [DataType(DataType.Date)]
        public DateTime? DateOfBirth { get; set; }

        [Required]
        [Range(0.0, 4.0)]
        public double GPA { get; set; }

        [NotMapped]
        public int Age => DateOfBirth.HasValue ? DateTime.Now.Year - DateOfBirth.Value.Year : 0;

        [NotMapped]
        public string GPAScale
        {
            get
            {
                if (GPA >= 3.7) return "Excellent";
                if (GPA >= 3.0) return "Very Good";
                if (GPA >= 2.0) return "Good";
                if (GPA >= 1.0) return "Satisfactory";
                return "Unsatisfactory";
            }
        }

        [Required]
        [Display(Name = "Program")]
        public string ProgramCode { get; set; }

        [ForeignKey("ProgramCode")]
        [ValidateNever] // Skip validation on the navigation property.
        public ProgramOfStudy Program { get; set; }
    }
}
