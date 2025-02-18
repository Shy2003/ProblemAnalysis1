using Microsoft.EntityFrameworkCore;
using ProblemAnalysis1Assignment.Data;

var builder = WebApplication.CreateBuilder(args);

// 1. Register the Database Context
builder.Services.AddDbContext<ApplicationDbContext>(options =>
    options.UseSqlServer(builder.Configuration.GetConnectionString("DefaultConnection")));

// 2. Add MVC services
builder.Services.AddControllersWithViews();

var app = builder.Build();

// 3. Serve static files (from wwwroot)
app.UseStaticFiles();

// 4. Enable routing
app.UseRouting();

app.UseAuthorization();

// 5. Map the default route
app.MapControllerRoute(
    name: "default",
    pattern: "{controller=Students}/{action=Index}/{id?}");

// 6. Run the application
app.Run();
