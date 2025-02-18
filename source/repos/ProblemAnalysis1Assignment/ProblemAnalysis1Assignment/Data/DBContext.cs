using Microsoft.EntityFrameworkCore;
using ProblemAnalysis1Assignment.Models;

namespace ProblemAnalysis1Assignment.Data
{
    public class ApplicationDbContext : DbContext
    {
        public ApplicationDbContext(DbContextOptions<ApplicationDbContext> options)
            : base(options)
        {
        }

        public DbSet<Student> Students { get; set; }
        public DbSet<ProgramOfStudy> Programs { get; set; }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);

            modelBuilder.Entity<ProgramOfStudy>().HasData(
                new ProgramOfStudy { Code = "CPA", Name = "Computer Programmer Analyst" },
                new ProgramOfStudy { Code = "BACS", Name = "Bachelor of Applied Computer Science" }
            );

            modelBuilder.Entity<Student>().HasData(
                new Student
                {
                    Id = 1,
                    FirstName = "Bart",
                    LastName = "Simpson",
                    DateOfBirth = new DateTime(1971, 5, 31),
                    GPA = 2.7,
                    ProgramCode = "CPA"
                },
                new Student
                {
                    Id = 2,
                    FirstName = "Lisa",
                    LastName = "Simpson",
                    DateOfBirth = new DateTime(1973, 8, 5),
                    GPA = 4.0,
                    ProgramCode = "BACS"
                }
            );
        }
    }
}
