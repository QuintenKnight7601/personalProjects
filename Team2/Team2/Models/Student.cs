using System;
using System.ComponentModel.DataAnnotations;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Team2.Models
{
    public class Student
    {
        public int Id { get; set; }
        public string First { get; set; }
        public string Middle { get; set; }
        public string Last { get; set; }

        [DataType(DataType.Date)]
        public DateTime Birthdate { get; set; }
        [DataType(DataType.Date)]
        public DateTime Graduation { get; set; }
        public string Degree { get; set; }
    }
}
