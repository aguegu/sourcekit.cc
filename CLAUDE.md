# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is the documentation website for Sourcekit Electronics Ltd, built with VitePress. It documents hardware products (PiTray clip, PiTray mini, MeshMass remote control kits) in English and Simplified Chinese. Circus Goggles is deprecated.

## Commands

```bash
npm run dev       # Start dev server with hot reload
npm run build     # Build static site to .vitepress/dist/
npm run preview   # Preview production build locally
```

There are no test or lint commands.

## Architecture

**Stack:** VitePress 2.0.0-alpha.16 + Vue 3, with `@mdi/font` for Material Design Icons.

**Content lives in `docs/`:**
- `docs/*.md` — English product pages
- `docs/zh/*.md` — Chinese translations (mirrors English structure)
- `docs/index.md` — Home page (uses VitePress `home` layout with hero/features)
- `docs/public/` — Static assets (images organized under `images/`, PDFs, favicons)

**Configuration in `.vitepress/`:**
- `config.js` — Site metadata, i18n locales (en root `/`, zh at `/zh/`), nav, sidebar, Google Analytics (`G-TK6CPWVPRE`)
- `theme/index.js` — Extends default theme, registers MDI font
- `theme/style.css` — CSS variable overrides for brand colors, dark mode

**Deployment:** GitHub Actions (`.github/workflows/deploy.yml`) auto-deploys to GitHub Pages on push to `main`.

## i18n Convention

Content pages should exist in both `docs/` (English) and `docs/zh/` (Chinese) for consistency. Navigation and sidebar labels are duplicated per locale in `config.js`. New products may be added in English first, with Chinese translations following.

**Note:** Circus Goggles is deprecated and hidden from all locale navigations.

## Content Conventions

Product pages use ATX-style headers (`#`) for titles. Markdown files include embedded YouTube iframes for demo videos, GitHub discussion links for support, and step-by-step installation images referencing `docs/public/images/`.
