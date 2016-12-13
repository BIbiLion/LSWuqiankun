using System;
using System.Collections.Generic;
using System.Text;

namespace System.Drawing.PieChart
{
    public class ColorArray
    {
        public ColorArray()
        {
            m_colors = new List<Color>();
        }

        public void Add(Color color)
        {
            m_colors.Add(color);
        }

        public Color[] Get()
        {
            return m_colors.ToArray();
        }

        private List<Color> m_colors;
    }

    public class DecimalArray
    {
        public DecimalArray()
        {
            m_values = new List<decimal>();
        }

        public void Add(double value)
        {
            m_values.Add(new decimal(value));
        }

        public decimal[] Get()
        {
            return m_values.ToArray();
        }

        private List<decimal> m_values;
    }

    public class StringArray
    {
        public StringArray()
        {
            m_values = new List<string>();
        }

        public void Add(string value)
        {
            m_values.Add(value);
        }

        public string[] Get()
        {
            return m_values.ToArray();
        }

        private List<string> m_values;
    }

    public class FloatArray
    {
        public FloatArray()
        {
            m_values = new List<float>();
        }

        public void Add(float value)
        {
            m_values.Add(value);
        }

        public float[] Get()
        {
            return m_values.ToArray();
        }

        private List<float> m_values;
    }

    public class PieSliceArray
    {
        public PieSliceArray()
        {
            m_values = new List<PieSlice>();
        }

        public void Add(PieSlice pieSlice)
        {
            m_values.Add(pieSlice);
        }

        public PieSlice[] Get()
        {
            return m_values.ToArray();
        }

        private List<PieSlice> m_values;
    }
}
