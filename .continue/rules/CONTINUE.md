# Sourcekit.cc Project Guide

## Project Overview

**Sourcekit.cc** is the official documentation website for Sourcekit Electronics hardware products, primarily focusing on PiTray products for Raspberry Pi Compute Module 4. The site serves as both product documentation and a marketing platform for hardware products.

### Key Technologies
- **VitePress**: Static site generator (v2.0.0-alpha.16)
- **Node.js**: JavaScript runtime (ES modules)
- **Material Design Icons**: Icon library for UI elements
- **Google Analytics**: For traffic tracking (G-TK6CPWVPRE)

### High-level Architecture
The project is a static documentation website built with VitePress featuring:
- Modern documentation with excellent performance
- Multi-language support (English and Chinese)
- Product documentation with images, specifications, and guides
- E-commerce integration through distributor links

## Getting Started

### Prerequisites
- Node.js (version 16 or higher recommended)
- npm or yarn package manager
- Git for version control

### Installation
```bash
# Clone the repository
git clone https://github.com/aguegu/sourcekit.cc.git
cd sourcekit.cc

# Install dependencies
npm install
```

### Development
```bash
# Start VitePress development server
npm run dev
```

### Building for Production
```bash
# Build VitePress site
npm run build

# Preview built site
npm run preview
```

### Testing
Currently, the project doesn't have automated tests. Manual testing involves:
1. Running the development server
2. Checking all documentation pages render correctly
3. Verifying links and images work
4. Testing responsive design on different devices

## Project Structure

```
sourcekit.cc/
├── .continue/rules/          # Continue IDE configuration (this file)
├── .vitepress/               # VitePress configuration
│   └── config.js            # Site configuration
├── docs/                     # Documentation content
│   ├── public/              # Static assets (images, PDFs, icons)
│   │   ├── images/         # Product images and logos
│   │   ├── CNAME           # Custom domain configuration
│   │   └── *.pdf           # Product documentation PDFs
│   ├── index.md            # English homepage
│   ├── PiTray-mini.md      # PiTray mini product documentation (English)
│   ├── PiTray-clip.md      # PiTray clip product documentation (English)
│   ├── CircusGoggles.md    # CircusGoggles product documentation (English)
│   └── zh/                 # Chinese documentation
│       ├── index.md        # Chinese homepage
│       ├── PiTray-mini.md  # PiTray mini 产品文档 (中文)
│       ├── PiTray-clip.md  # PiTray clip 产品文档 (中文)
│       └── CircusGoggles.md # CircusGoggles 产品文档 (中文)

├── package.json            # Project dependencies and scripts
├── package-lock.json       # Dependency lock file
├── README.md               # Project README
└── .gitignore              # Git ignore rules
```

### Key Files and Their Roles

1. **`.vitepress/config.js`** - Main VitePress configuration
   - Site metadata (title, description)
   - Navigation and sidebar configuration
   - Google Analytics setup
   - Theme settings

2. **`docs/index.md`** - Homepage
   - Hero section with product features
   - Navigation to main products

3. **`docs/PiTray-mini.md`** - Main product documentation
   - Product specifications and features
   - Getting started guides
   - Troubleshooting information
   - Distributor links

4. **`index.html`** - Docsify configuration (legacy)
   - Alternative documentation system
   - Social sharing functionality
   - Mobile-responsive design

5. **`package.json`** - Project configuration
   - Dependencies (VitePress, Material Design Icons)
   - Scripts for development and build

## Development Workflow

### Coding Standards
- **Markdown**: Use standard Markdown with VitePress extensions
- **Images**: Store in `docs/public/images/` with descriptive names
- **Links**: Use relative paths for internal links
- **Localization**: Create `_cn.md` files for Chinese versions
- **Commit Messages**: Use conventional commits when possible

### Content Updates
1. **Add new product documentation**:
   - Create new `.md` file in `docs/` directory
   - Add to sidebar in `.vitepress/config.js`
   - Add product images to `docs/public/images/`
   - Create Chinese version if needed (`filename_cn.md`)

2. **Update existing documentation**:
   - Edit the relevant `.md` file
   - Update images if needed
   - Test changes locally with `npm run docs:dev`

3. **Add new distributor**:
   - Add distributor logo to `docs/public/images/`
   - Update distributor links in product documentation
   - Follow existing HTML/image link format

### Build and Deployment
The site is deployed as a static site. The build process:
1. `npm run docs:build` generates static files in `.vitepress/dist/`
2. Files are deployed to hosting (likely GitHub Pages)
3. Custom domain configured via `docs/public/CNAME`

### Contribution Guidelines
1. Fork the repository
2. Create a feature branch
3. Make changes with clear commit messages
4. Test changes locally
5. Submit pull request with description of changes

## Key Concepts

### Product Documentation Structure
Each product documentation follows this pattern:
1. **Title and Version** - Product name and version number
2. **Overview** - Brief product description
3. **Features** - Key features list
4. **Specifications** - Technical details
5. **Getting Started** - Setup instructions
6. **Troubleshooting** - Common issues and solutions
7. **Distributors** - Where to buy with logos and links

### Internationalization (i18n) Support
- **English documentation**: Root directory files (`docs/ProductName.md`)
- **Chinese documentation**: Language-specific directory (`docs/zh/ProductName.md`)
- **Language switcher**: Built-in VitePress language selector in navigation
- **Locale-specific configuration**: Separate navigation, sidebar, and metadata for each language
- **Automatic routing**: `/` for English, `/zh/` for Chinese

### Static Assets Management
- Product images in `docs/public/images/`
- PDF documents in `docs/public/`
- Icons and logos follow Material Design Icons

## Common Tasks

### Adding a New Product
```bash
# 1. Create English documentation file
touch docs/NewProduct.md

# 2. Create Chinese version
touch docs/zh/NewProduct.md

# 3. Add product images to docs/public/images/
# 4. Update .vitepress/config.js sidebar for both languages
# 5. Test locally: npm run dev
```

### Updating Distributor Links
1. Edit the relevant product `.md` file
2. Find the "Where to buy" section
3. Add new distributor in the same HTML format:
   ```html
   <a href="LINK" target="_blank">
     <img src="/images/distributor-logo.jpg" alt="Distributor Name">
   </a>
   ```
4. Add distributor logo to `docs/public/images/`

### Building and Previewing
```bash
# Build the site
npm run docs:build

# Preview the built site
npm run docs:preview

# The site will be available at http://localhost:4173/
```

## Troubleshooting

### Common Issues

1. **VitePress dev server not starting**
   ```bash
   # Clear node_modules and reinstall
   rm -rf node_modules
   npm install
   ```

2. **Images not displaying**
   - Check image paths are relative to `/images/`
   - Verify images are in `docs/public/images/`
   - Check file permissions

3. **Build errors**
   ```bash
   # Check for syntax errors in Markdown
   # Verify all links are correct
   # Check console for specific error messages
   ```

4. **Chinese characters not displaying properly**
   - Ensure files are UTF-8 encoded
   - Check browser encoding settings
   - Verify proper HTML meta tags

### Debugging Tips
- Use `npm run docs:dev` for live reload during development
- Check browser console for JavaScript errors
- Validate Markdown syntax with online tools
- Test on multiple browsers for compatibility

## References

### Official Documentation
- [VitePress Documentation](https://vitepress.dev/)
- [Docsify Documentation](https://docsify.js.org/)
- [Material Design Icons](https://materialdesignicons.com/)
- [Raspberry Pi Documentation](https://www.raspberrypi.org/documentation/)

### Project Resources
- [GitHub Repository](https://github.com/aguegu/sourcekit.cc)
- [GitHub Discussions](https://github.com/aguegu/sourcekit.cc/discussions)
- [Live Site](https://sourcekit.cc/)

### Related Projects
- [PiTray Mini Product Page](https://sourcekit.cc/PiTray-mini)
- [Raspberry Pi Compute Module 4](https://www.raspberrypi.org/products/compute-module-4/)
- [Sourcekit Electronics](https://sourcekit.cc/)

---

*This documentation was generated for the Continue IDE. It provides developers with essential information about the Sourcekit.cc project structure, development workflow, and common tasks.*